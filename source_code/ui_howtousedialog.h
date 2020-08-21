/********************************************************************************
** Form generated from reading UI file 'howtousedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOWTOUSEDIALOG_H
#define UI_HOWTOUSEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_HowtoUseDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTextBrowser *textBrowser;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *HowtoUseDialog)
    {
        if (HowtoUseDialog->objectName().isEmpty())
            HowtoUseDialog->setObjectName(QString::fromUtf8("HowtoUseDialog"));
        HowtoUseDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(HowtoUseDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(HowtoUseDialog);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        textBrowser = new QTextBrowser(HowtoUseDialog);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout->addWidget(textBrowser);

        buttonBox = new QDialogButtonBox(HowtoUseDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(HowtoUseDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), HowtoUseDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), HowtoUseDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(HowtoUseDialog);
    } // setupUi

    void retranslateUi(QDialog *HowtoUseDialog)
    {
        HowtoUseDialog->setWindowTitle(QCoreApplication::translate("HowtoUseDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("HowtoUseDialog", "How to Use", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("HowtoUseDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-style:italic;\">Welcome to the Daily Audio Journal. Not much hassle to get started. But here are some descriptions of the features you have to help you out.\302\240</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\"><br /></span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\""
                        "><span style=\" font-size:8pt; font-weight:600;\">Options:</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">\302\240 \302\240 Select Directory-</span><span style=\" font-size:8pt;\"> Change the directory where future recording files will be stored in.\302\240</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">\302\240 \302\240 </span><span style=\" font-size:8pt; font-weight:600;\">How to Use-</span><span style=\" font-size:8pt;\"> Hello. Its me.</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">File Calendar\302\240-</span><span style=\" font-size:8pt;\"> Select any date. Naviga"
                        "te easily with the green arrows and month button on top.</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">\302\240\302\240 \302\240\302\240\302\240 \302\240\302\240\302\240 \302\240\302\240\302\240 \302\240\302\240\302\240 \302\240\302\240 \302\240 \302\240\302\240Dates with recordings will be marked with yellow shading.</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">Timer</span><span style=\" font-size:8pt;\"> - Track's the length of your recording. Freezes upon stopping recording.\302\240</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"><br /></p>\n"
"<p align=\"center\" style=\" m"
                        "argin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">Recording Buttons:</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">\302\240 \302\240 Start Record-</span><span style=\" font-size:8pt;\"> Click to begin recording on the currently selected date.</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">\302\240 \302\240 </span><span style=\" font-size:8pt; font-weight:600;\">Pause/Resume-</span><span style=\" font-size:8pt;\"> Click to pause the recording process, will freeze timer. Click to resume the recording process, will continue timer.</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left"
                        ":0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">\302\240 \302\240 </span><span style=\" font-size:8pt; font-weight:600;\">Stop Record-</span><span style=\" font-size:8pt;\">\302\240Click to stop a recording that has been started or paused. Will freeze timer.</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">\302\240 \302\240 </span><span style=\" font-size:8pt; font-weight:600;\">Clear Timer-</span><span style=\" font-size:8pt;\"> Click to reset the timer to 0 hours, 0 minutes, and 0 seconds.</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\""
                        "><span style=\" font-size:8pt; font-weight:600;\">Playback Buttons:</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">\302\240 \302\240 Play-</span><span style=\" font-size:8pt;\"> Begin playback for the selected date.</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">\302\240 \302\240 </span><span style=\" font-size:8pt; font-weight:600;\">Pause-</span><span style=\" font-size:8pt;\"> Pause playback for the selected date.</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">\302\240 \302\240 </span><span style=\" font-size:8pt; font-weight:600;\">Stop</span><span style=\" font-size:8pt;\">- Stop pl"
                        "ayback for the selected date.\302\240</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">\302\240 \302\240 </span><span style=\" font-size:8pt; font-weight:600;\">Delete-</span><span style=\" font-size:8pt;\"> Destroy the file for the selected date.\302\240</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">Status Bar:</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">\302\240 \302\240 Playba"
                        "ck Status' -</span><span style=\" font-size:8pt;\">Found on the far right. Will display &quot;Playing, Paused, Stopped, or No Entry Recorded&quot; depending on the state of playback.</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">\302\240 \302\240 Adjustable Playback Bar-</span><span style=\" font-size:8pt;\"> Bar with blue button. Drag button to start playback at a certain location.</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">\302\240 \302\240 </span><span style=\" font-size:8pt; font-weight:600;\">Percentage Playback Bar-</span><span style=\" font-size:8pt;\"> Will indicate how much of the journal entry has been played so far.\302\240</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px;"
                        " margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"><br /></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HowtoUseDialog: public Ui_HowtoUseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOWTOUSEDIALOG_H
