#include "dailyaudiojournal.h"
#include "ui_mainwindow.h"
#include <QUrl>
#include <QDebug>
#include <QLCDNumber>
#include <QFileInfo>
#include <QMessageBox>
#include <QTextBrowser>
#include <QDir>
#include <QFileDialog>
#include <QTextCharFormat>




DailyAudioJournal::DailyAudioJournal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)



{
    ui->setupUi(this);

    //Initializing Variables
    {

    initalize_dateRecoringUrlStringMap(dateRecoringUrlStringMap);
    QHash<QDate, QString>d  = dateRecoringUrlStringMap;
    QUrl temp_url;
    baseUrl = QUrl(getBaseUrlText());
    dateToPlay = QDate::currentDate();
    DateMaking = false;
    DateReplacing = false;
    noRecordingSet = true;
    }


    //Recording setup
    {
    signalMapperStartRecording = new QSignalMapper (this) ;
    audioRecorder = new QAudioRecorder;
    QAudioEncoderSettings audioSettings;
    audioSettings.setCodec("audio/amr");
    audioSettings.setQuality(QMultimedia::HighQuality);
    audioRecorder->setEncodingSettings(audioSettings);
   }

    //Playback setup
   {
   audioPlayer = new QMediaPlayer;
   slider = new QSlider();
   bar = new QProgressBar();

   connect(audioPlayer, &QMediaPlayer::durationChanged, slider, &QSlider::setMaximum);
   connect(audioPlayer, &QMediaPlayer::positionChanged, slider,&QSlider::setValue);
   connect(slider,&QSlider::sliderMoved,audioPlayer,&QMediaPlayer::setPosition);

   connect(audioPlayer, &QMediaPlayer::durationChanged, bar, &QProgressBar::setMaximum);
   connect(audioPlayer,&QMediaPlayer::positionChanged,bar,&QProgressBar::setValue);

   slider->setOrientation(Qt::Horizontal);
   ui->statusbar->addPermanentWidget(slider);
   ui->statusbar->addPermanentWidget(bar);
    }

    //Timer Setup
   {
    timer = new QTimer(this);
    time = new QTime();
    time->setHMS(0,0,0);
    reset = false;
    connect(ui->stopButton, SIGNAL(released()),this, SLOT(endTimer()));
    connect(timer, SIGNAL(timeout()),this,SLOT(displayTimer())); //associating the timeout() function with the myfunction() function
    }



}

/*!
 * \brief After creating a QUrl from jDate, sets up audioRecorder to ouput at the QUrl and begins recording.
 * Initalizes audioPlayer with it set to play the newly recording file and calls addtoDateUrlFile() with
 * a pointer to the QUrl and the jDate as params.
 * \param jDate - Date that the file will be assocaited with in an integer form
 */
void DailyAudioJournal::StartRecording(int jDate){


    if (audioRecorder->state() == QMediaRecorder::PausedState) {
        QMessageBox::information(this,"Trying to Resume?","It seems like you are trying to resume a paused recording."
                                                          " Please use the Pause/Resume button!");
        return;
    }

    QDate date = QDate::fromJulianDay(jDate);

    QUrl audioFileUrl = makeAudioFileUrl(baseUrl, date);

    if (DateMaking || DateReplacing) {
        audioPlayer->setMedia(audioFileUrl);
        audioPlayer->setVolume(50);

        startTimer();

        audioRecorder->setOutputLocation(audioFileUrl);

        QUrl* url_ptr = new QUrl(getFromdateRecoringUrlStringMap(QDate::fromJulianDay(jDate)));
        //adding the files url to the url_Map_file
       addtoDate_Url_File(url_ptr, QDate::fromJulianDay(jDate));

       audioRecorder->record();
    }



}

/*!
 * \brief Checks the state of the audioRecorder.
 * If its in PausedState, begins audioRecorder and start() the timer with 1000ms as param.
 * If its in RecordingState, pauses audioRecorder.
 * If its in neither state,
 * outputs a QMessageBox:warning stating that audioRecorder has not been initiated by user.
 */
void DailyAudioJournal::pauseResumeRecording(){

    if (audioRecorder->state() == QMediaRecorder::RecordingState) {
        audioRecorder->pause();
        this->timer->stop();
    }
    else if (audioRecorder->state() == QMediaRecorder::PausedState) {
        audioRecorder->record();
         this->timer->start(1000);
    }
    else {
        QMessageBox::warning(this,"Recording Not Started", "The recording cannot be paused because you didnt start recording!");
    }
}

/*!
 * \brief Stops audioRecorder and sets time to O Hours, O Minutes, and O Seconds and
 * flags reset boolean as 'true'.
 */
void DailyAudioJournal::stopRecording(){
    audioRecorder->stop();
    time->setHMS(0,0,0);
    reset = true;
}

/*!
 * \brief Calls start() for timer with 1000ms
 */
void DailyAudioJournal::startTimer() {
    this->timer->start(1000);}
/*!
 * \brief Calls stop() for timer
 */
void DailyAudioJournal::endTimer() {
    this->timer->stop();
}

/*!
 * \brief If reset is false,
 *  time points to a new pointer of QTime with +1000ms
 * compared to the previous time.
 *  If reset is true, flags reset as false.
 * Converts the QTime hour, minute, and second portions of time to ints.
 * The int versions of the 3 time poritions are converted to QString.
 * The 3 strings are appended to form time_text which is displayed in the QLCD Number widget.
 */
void DailyAudioJournal::displayTimer() {
    if (!reset) {
        time = new QTime(time->addMSecs(1000));
    } else
        reset = false;

   //Gives the current time stored in the 'time' QTime object
   int hour = time->hour();
   int minute = time->minute();
   int second = time->second();

   //Converting Time to Strings
   QString hour_string = TimetoQString(hour);
   QString minute_string = TimetoQString(minute);
   QString second_string = TimetoQString(second);


   //Adding hour, minutes, and seconds strings as one string
   QString time_text = hour_string + ":" +  minute_string + ":" +  second_string;

    ui->lcdNumber->setDigitCount(8);

    ui->lcdNumber->display(time_text);
}

/*!
 * \brief Converts integer into QString,
 * but adds 0 to the front of QString if the int is from 0-9 inclusive.
 * \param time - The integer represenation of a portion of time.
 * \return -The QString representation of the param time.
 */
QString  DailyAudioJournal::TimetoQString(int &time){
    QString tensPlace = "";

    //if time is in the single digits, add a extra zero in front of it for good formatting
    if (time <= 9)
        tensPlace = "0";

    return tensPlace + QString::number(time);
}

/*!
 * \brief Generates an appropriate QUrl from the base_url and date,
 * that will both serve to name the file and to point to its location.
 * \param base_url - Directory in which file must be stored
 * \param date - Date that the file will be named after
 * \return - QUrl for the file
 */
QUrl DailyAudioJournal::makeAudioFileUrl (QUrl  base_url, QDate date){

      //int file_number = dateRecoringUrlStringMap.size();

      QString file_name = "audio_entry_" + date.toString().replace(" ","_") + ".wav";

      QUrl file_url(file_name);

      file_url.setScheme(QString());

      QString total_url_string = base_url.resolved(file_url).toEncoded();

      QFile file(total_url_string);

      addTodateRecordingUrlStringMap(total_url_string, date);

      file_url = QUrl::fromLocalFile(total_url_string);  //creates the .wav file

      return file_url;
    }

QUrl DailyAudioJournal::getLastAudioFileUrl(QHash <QDate, QString>& dateRecoringUrlStringMap){

    QUrl url(dateRecoringUrlStringMap[QDate::currentDate()]);

    return url;
}

/*!
 * \brief Reads the url_Map.txt file
 * and uses the data about date QStrings and file url QStrings
 * to form the keys and the values of the dateRecordingUrlStringMap, respectivley.
 * \param dateRecoringUrlStringMap - Map that will be loaded with all the keys and values found on the url_Map.txt file
 */
void DailyAudioJournal::initalize_dateRecoringUrlStringMap(QHash <QDate, QString>& dateRecoringUrlStringMap){

  QFile url_Map_file(QDir::currentPath() + "/url_Map.txt");

  if (!url_Map_file.open(QFile::ReadWrite | QFile::Text))
    QMessageBox::warning(this,"title","url_Map_file.txt not open");

  else  //File has been opened for reading and now will be read from line-by-line and each line will be converted to QUrl and pushed_back into dateRecoringUrlStringMap;
  {
     QTextStream in(& url_Map_file);
     while (!in.atEnd())
     {
        //read the first line of the pair, the url string
        QString url_string = in.readLine();

        {
            //read the second line of the pair, the date string
            QDate recording_date = QDate::fromString(in.readLine());
            dateRecoringUrlStringMap[recording_date] = url_string;
            QFile file(url_string);
            if (!file.exists() && url_string.compare("[deleted]")!=0) {
                dateRecoringUrlStringMap[recording_date] = "[deleted]";
                addtoDate_Url_File(nullptr,recording_date);
                unshadeDateCell(recording_date);
                continue;
            }
            if (url_string.compare("[deleted]")!=0) //check if string is not '[deleted]'
                shadeDateCell(recording_date);
            else
                //removing yellow filling
                unshadeDateCell(recording_date);
        }



     }
      url_Map_file.close();

  }
}

/*!
 * \brief If a nullptr is passed in with a date, the date is written onto the file
 * along with QString "[deleted]" to indicate no file_url_ptr was associated with the date
 * Otherwise, a QString formed from the file_url_pointer will be appended with the baseUrl to form a string representation
 * of the file location, which will be added to the file along with the date.
* \param file_url_ptr - A pointer to the QUrl of the file that will be associated with the date.
 * \param date - The date to be added to the file as a String.
 */
void DailyAudioJournal::addtoDate_Url_File(QUrl* file_url_ptr, QDate date)
{
    QString total_url_string;

    if (file_url_ptr != nullptr) {
    QUrl file_url = *file_url_ptr;

       file_url.setScheme(QString());
       // prints QUrl("file:///home/user/file.txt")
       total_url_string = baseUrl.resolved(file_url).toEncoded();
    }

    else
        total_url_string = "[deleted]";


     QString filename = QDir::currentPath() + "/url_Map.txt";
     QFile file(filename);
     if (file.open(QIODevice::ReadWrite)) {
        QTextStream stream(&file);
        try {
            QString line = QString(file.readLine());
            if (line.isEmpty())
                {
                      stream << total_url_string  << Qt::endl;
                      stream << date.toString()  << Qt::endl;
                }

            while (!line.isEmpty()) {
                line = QString(file.readLine());

                if (line.isEmpty())
                {
                    stream << total_url_string  << Qt::endl;
                    stream << date.toString()  << Qt::endl;
                    break;
                }

                    }



            } catch ( std::exception& e) {
                 QMessageBox::warning(this,"title","File location was not stored!");
            }
    }

     delete file_url_ptr;
}


//A slot in the MainWindow that will respond to the 'clicked()' signal from the fileCalender
//the date that was clicked on will serve as a key to

/*!
 * \brief Called whenever a cell on the FileCalender is clicked. Configures the start,pause/resume, and record buttons 
 * to work with the url_string that is associated with clickedDate. If there is no reocording set, a message box will appear
 * stating that the Recording Date is set to clickedDate. Otherwise no change on the UI will occur.
 * \param clickedDate - The date which is used to config the buttons and find the url_string value on the dateRecordingUrlStringMap
 */
void DailyAudioJournal::on_fileCalender_clicked(const QDate &clickedDate)
{
    //A date has been clicked

    dateToPlay = clickedDate;

    QUrl url(dateRecoringUrlStringMap[dateToPlay]);

    audioPlayer->setMedia(url);
    audioPlayer->setVolume(50);


    //check if the date, as a key has a value on the date_time_map
    if (dateRecoringUrlStringMap.find(clickedDate) != dateRecoringUrlStringMap.end() && dateRecoringUrlStringMap[clickedDate] != nullptr
            && dateRecoringUrlStringMap[clickedDate] != "[deleted]") {

        noRecordingSet = false;
        unconfigStartStopRecording();
        configStartStopRecording(clickedDate);


     }

    else {  //if its does not exist then a message box will open asking if they want to create an entry at that date
            qDebug() << "filler";

            noRecordingSet = true;

            //QMessageBox
            QMessageBox::about(this, "Recording Date Set", "Date set at " + clickedDate.toString());

            unconfigStartStopRecording();
            configStartStopRecording(clickedDate);


    }
}

/*!
 * \brief Sets up a QSignalMapper so that the startButton, upon release,
 *  can send to StartRecording(int) the date the user selects.
 * Connects the pauseButton relased() with pauseResumeRecording().
 * Connects the stopButton released() with stopRecording().
 * \param date - Date that has been selected
 */
void DailyAudioJournal::configStartStopRecording(QDate date){

    connect (ui->startButton, SIGNAL(released()), signalMapperStartRecording, SLOT(map())) ;

    signalMapperStartRecording -> setMapping (ui->startButton, date.toJulianDay()) ;

    connect (signalMapperStartRecording, SIGNAL(mapped(int)), this, SLOT(StartRecording(int))) ;

    connect(ui->pauseButton, SIGNAL(released()), this, SLOT(pauseResumeRecording()));

    connect(ui->stopButton, SIGNAL(released()),this, SLOT(stopRecording()));
}

/*!
 * \brief Removes connect between startButton, pasuseButton, and stopButton relased() signals
 * and the slots the were associated with in configStartStopRecording(int).
 */
void DailyAudioJournal::unconfigStartStopRecording(){
    disconnect (ui->startButton, SIGNAL(released()), signalMapperStartRecording, SLOT(map())) ;

    disconnect (signalMapperStartRecording, SIGNAL(mapped(int)), this, SLOT(StartRecording(int))) ;

    disconnect(ui->pauseButton, SIGNAL(released()), this, SLOT(pauseResumeRecording()));

    disconnect(ui->stopButton, SIGNAL(released()),this, SLOT(stopRecording()));
}

/*!
 * \brief Opens up the base_directory_file and reads in the baseUrlText QString.
 * \return -The baseUrlText QString as read from the file.
 */
QString DailyAudioJournal::getBaseUrlText(){

    QString baseUrlText = "";
    QString temp = "";




    QFile base_directory_file(QDir::currentPath() + "/base_directory.txt");



    if (base_directory_file.size() != 0) //checking if the file is empty or not
        {
            if (!base_directory_file.open(QFile::ReadWrite | QFile::Text))
                QMessageBox::warning(this,"title","base_directory.txt not open");

            else  //File has been opened for reading and now will be read from line-by-line and each line will be converted to QUrl and pushed_back into dateRecoringUrlStringMap;
               {
                    QTextStream in(& base_directory_file);
                    while (!in.atEnd())
                        {
                            temp = in.readLine();
                            if (temp.compare("") != 0 && temp.compare("/") != 0 && temp.compare(" ") != 0) {
                                baseUrlText = temp;
                            }



                        }
                             base_directory_file.close();

                 }
          }

    else {

        baseUrlText = set_or_update_base_url_file();
        }


    return baseUrlText;
}

DailyAudioJournal::~DailyAudioJournal()
{
    delete ui;
}


void DailyAudioJournal::on_actionSet_Directory_triggered()
{


   baseUrl.setUrl(set_or_update_base_url_file());
}

/*!
 * \brief In an infinite loop, Opens up QFileDialoug and prompts user to select a directory to store audio files.
 * If directory has no spaces, the directory is valid and its location is set as the baseUrl_name, then breaks loop.
 * Else, a QMessageBox:warning informs user that the directory is invalid and continues the loop.
 * \return
 */
QString DailyAudioJournal::set_or_update_base_url_file(){

    QString baseUrl_name;


    while (1) {
        QMessageBox::information(this,"Directory Setting",
                             "Please create or select a directory to store all your recording files!");
        baseUrl_name = (QFileDialog::getExistingDirectory(this, tr("Set Directory"),
                                                        QDir::homePath(),
                                                        QFileDialog::ShowDirsOnly

                                                        | QFileDialog::DontResolveSymlinks)) + "/";

        if (baseUrl_name.indexOf(" ") >= 0)
            QMessageBox::warning(this,"Directory Invalid",
                             "This directory has invalid characters, make sure your directory has no spaces or invalid characters!");
//        else if (baseUrl_name.compare("") == 0)
//            QMessageBox::warning(this,"No Directory Selected",
//                             "You didn't select a directory, please do so!");
        else
            break;
    }



    QFile base_directory_file(QDir::currentPath() + "/base_directory.txt"); //base_directory_file is placed in the absoulte
                                                                            //path of the applications current directory
    if (base_directory_file.open(QIODevice::ReadWrite)) {
                QTextStream stream(&base_directory_file);
                try {


                    QString line = QString(base_directory_file.readLine());
                    stream << baseUrl_name  << Qt::endl;

                } catch ( std::exception& e) {
                     QMessageBox::warning(this,"title","Base url was not stored!");
                }
    }

    return baseUrl_name;
}

/*!
 * \brief If the date is not found in the dateRecordingStringMap or points to a NULL,
 * or to a "[deleted]" Qstring, the file_url_string is set as the value and the date as a key.
 * The Start Stop and Pause buttons are configured for the date.
 * Appropriate flags are set or cleared.
 * Else, user is asked via QMessageBox whether they would like to replace the recording associated with
 * the date. If yes, the file_url_string is set as the value and the date as a key.
 * the Start Stop and Pause buttons are configured for the date. If no, the time is made to 0.
 * Appropriate flags are set or cleared.
 * \param file_url_string
 * \param date
 */
void DailyAudioJournal::addTodateRecordingUrlStringMap(QString file_url_string, QDate date) {

    if (!dateRecoringUrlStringMap.contains(date)
            || dateRecoringUrlStringMap[date] == nullptr || dateRecoringUrlStringMap[date] == "[deleted]"){
        dateRecoringUrlStringMap[date] = file_url_string;
        unconfigStartStopRecording();
        configStartStopRecording(date);
        shadeDateCell(date);
        DateMaking = true;
        DateReplacing = false;
    }
    else {
        QMessageBox::StandardButton replaceRecording = QMessageBox::question(this, "Replace Recording?",
                                                                            "Replace and store a recording at " + date.toString() + " ?",
                                                                            QMessageBox::Yes | QMessageBox::No);
        if (replaceRecording == QMessageBox::Yes){
            qDebug() << "Replacing recording for " + getFromdateRecoringUrlStringMap(date);
            dateRecoringUrlStringMap[date] = file_url_string;
            QFile fileToDelete(dateRecoringUrlStringMap[dateToPlay]);
            if (fileToDelete.remove())
                QMessageBox::information(this,"Previous Entry Removed", "Previous entry has been removed!");
            unconfigStartStopRecording();
            configStartStopRecording(date);
            DateMaking = false;
            DateReplacing = true;
        }
        else if (replaceRecording == QMessageBox::No){

            DateMaking = false;
            DateReplacing = false;
            time->setHMS(0,0,0);
            reset = true;
            displayTimer();

        }
    }


}
/*!
 * \brief Returns the dateRecordingUrlStringMap value using the date as the key.
 * If dateRecordingUrlStringMap does not have a value with the date, a nullptr is returned.
 * \param date
 * \return 
 */
QString DailyAudioJournal::getFromdateRecoringUrlStringMap(QDate date){
    if (dateRecoringUrlStringMap.contains(date))
        return dateRecoringUrlStringMap[date];
    else
        return nullptr;
}

/*!
 * \brief Shades a date cell into a yellow color.
 * \param date - The date whose assoicated cell is to be shaded.
 */
void DailyAudioJournal::shadeDateCell(QDate date){

   QTextCharFormat format;
   format.setBackground(Qt::yellow);
   ui->fileCalender->setDateTextFormat(date, format);
}

/*!
 * \brief Removes shading from a date cell.
 * \param date - The date whose associated cell is to be unshaded. 
 */
void DailyAudioJournal::unshadeDateCell(QDate date){
    QTextCharFormat format;
    format.setBackground(Qt::transparent);
    ui->fileCalender->setDateTextFormat(date, format);
}

/*!
 * \brief Resets the time object. Reset bool is set to true.
 * Timer displays reset time.
 */
void DailyAudioJournal::on_clearTimerButton_released()
{

    time->setHMS(0,0,0);
    reset = true;
    displayTimer();
}


/*!
 * \brief When pause button is triggered, the audioPlayer is paused,
 * and "Paused..." message shown.
 * Otherwise "No Entry Recorded is shown". 
 */
void DailyAudioJournal::on_actionPause_triggered()
{
    audioPlayer->pause();

    if (noRecordingSet)
        ui->statusbar->showMessage("No Entry Recorded");
    else
        ui->statusbar->showMessage("Paused...");
}

/*!
 * \brief When the stop button is triggered, the audioPlayer is stopped,
 * and "Stopped" message is shown.
 * Otherwise "No Entry Recorded is shown".
 */
void DailyAudioJournal::on_actionStop_triggered()
{
    audioPlayer->stop();
    if (noRecordingSet)
        ui->statusbar->showMessage("No Entry Recorded");
    else
        ui->statusbar->showMessage("Stopped");
}

/*!
 * \brief When the play button is triggered, the audioPlayer begins playing,
 * and "Playing" message is shown.
 * Otherwise "No Entry Recorded is shown".
 */
void DailyAudioJournal::on_actionPlay_triggered()
{
    audioPlayer->play();
    if (noRecordingSet)
        ui->statusbar->showMessage("No Entry Recorded");
    else
        ui->statusbar->showMessage("Playing");
}

/*!
 * \brief When the delete button is pressed, if the audio is playing it is paused.
 * If there is a valid url on the dateRecordingUrlStringMap for the date being played,
 * the user is prompted whether they would like to follow through on the deletion.
 * If so, the file is deleted, the date cell is unshaded, and a MessageBox confirming the deltetion
 * is projected. If the user decides not to follow through, nothing happens.
 * If the deletion fails, the user is informed the path of the file and prompted to manually delete it
 * and restart the application.
 * If there is no valid Url on the DateRecordingUrlStringMap, then a MessageBox informing the user
 * of this is projected.
 */
void DailyAudioJournal::on_actionDelete_triggered()
{
   if (audioPlayer->state() == QMediaPlayer::PlayingState)
        audioPlayer->pause();

    if (dateRecoringUrlStringMap[dateToPlay] != nullptr && dateRecoringUrlStringMap[dateToPlay] != "[deleted]") {

        QFile fileToDelete(dateRecoringUrlStringMap[dateToPlay]);

        QMessageBox::StandardButton deleteRecording = QMessageBox::question(this,"Remove Recording?", "Are you sure you want to delete your recording at " + dateToPlay.toString(),
                              QMessageBox::Yes | QMessageBox::No);


        if (deleteRecording == QMessageBox::Yes){
            if(fileToDelete.remove()) {
                //Make map value Null and indicate that on Url_File
                dateRecoringUrlStringMap[dateToPlay] = nullptr;
                QUrl null_url;
                addtoDate_Url_File(nullptr,dateToPlay);
                //removing yellow filling
                unshadeDateCell(dateToPlay);

                QMessageBox::information(this,"File Removed", "File Sucessfully Removed!");
            }
            else
                QMessageBox::information(this,"File Not Removed", "Failed to Remove File!\nManually delete the file: " + dateRecoringUrlStringMap[dateToPlay] + ".\nThen restart the app!");
        }
        else if (deleteRecording == QMessageBox::No){
           return;
            }


    }

    else
        QMessageBox::information(this,"No Entry Recorded", "There is no recording for " + dateToPlay.toString() + " !");

}

void DailyAudioJournal::on_actionHow_to_Use_triggered()
{

    h.exec();
}

void DailyAudioJournal::on_pushButton_released()
{
    h.exec();
}
