#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAudioRecorder>
#include <QMediaPlayer>
#include <QTimer>
#include <QTime>
#include <QMap>
#include <QFile>
#include <QDate>
#include <QSignalMapper>
#include <QSlider>
#include <QProgressBar>
#include "howtousedialog.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class DailyAudioJournal : public QMainWindow
{
    Q_OBJECT

public:
    DailyAudioJournal(QWidget *parent = nullptr);
    ~DailyAudioJournal();



    QUrl makeAudioFileUrl(QUrl, QDate date);

    QUrl getLastAudioFileUrl(QHash <QDate, QString>&);

    void addtoDate_Url_File(QUrl* url_ptr, QDate date);

    QString set_or_update_base_url_file();

    void initalize_dateRecoringUrlStringMap(QHash <QDate, QString>&);

    QString getBaseUrlText();

    QString TimetoQString(int &time);

    void addTodateRecordingUrlStringMap(QString, QDate);

    QString getFromdateRecoringUrlStringMap(QDate date);

    void configStartStopRecording(QDate clickedDate);

    void unconfigStartStopRecording();

    void shadeDateCell(QDate);

    void unshadeDateCell(QDate);




private slots:
    void StartRecording(int jDate);

    void pauseResumeRecording();

    void stopRecording();

    void startTimer();

    void endTimer();

    void displayTimer();

    void on_fileCalender_clicked(const QDate &date);

    void on_actionSet_Directory_triggered();

    void on_clearTimerButton_released();

    void on_actionPlay_triggered();

    void on_actionPause_triggered();

    void on_actionStop_triggered();

    void on_actionDelete_triggered();

    void on_actionHow_to_Use_triggered();

    void on_pushButton_released();

private:
    Ui::MainWindow *ui;

    /*!
     * \brief audioRecorder
     */
    QAudioRecorder* audioRecorder;

    QMediaPlayer* audioPlayer;

    QTimer *timer;       //an object of type QTimer

    QTime *time;         //QTime object that will be used in conjunction with timer

    bool reset;         //reset boolean to be used to track when timer keeps adding and when to set to '0' time

    QUrl baseUrl;

    QString BaseDirectoryFilePathName;

    QHash <QDate, QString> dateRecoringUrlStringMap;

    QSignalMapper* signalMapperStartRecording;

    bool DateMaking;

    bool DateReplacing; //bool to let program know if a date is being replaced with a new entry

    bool noRecordingSet;

    QDate dateToPlay;

    QSlider *slider;

    QProgressBar *bar;

    HowtoUseDialog h;






};
#endif // MAINWINDOW_H
