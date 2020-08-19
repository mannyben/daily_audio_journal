/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSet_Directory;
    QAction *actionPause;
    QAction *actionStop;
    QAction *actionPlay;
    QAction *actionDelete;
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pauseButton;
    QCalendarWidget *fileCalender;
    QSpacerItem *horizontalSpacer_2;
    QGridLayout *gridLayout;
    QPushButton *clearTimerButton;
    QPushButton *startButton;
    QPushButton *stopButton;
    QLCDNumber *lcdNumber;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;
    QToolBar *audio_playback_bar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(677, 540);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionSet_Directory = new QAction(MainWindow);
        actionSet_Directory->setObjectName(QString::fromUtf8("actionSet_Directory"));
        actionPause = new QAction(MainWindow);
        actionPause->setObjectName(QString::fromUtf8("actionPause"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icons8-pause-50.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPause->setIcon(icon);
        actionStop = new QAction(MainWindow);
        actionStop->setObjectName(QString::fromUtf8("actionStop"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/icons8-stop-50.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStop->setIcon(icon1);
        actionPlay = new QAction(MainWindow);
        actionPlay->setObjectName(QString::fromUtf8("actionPlay"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/icons8-play-50.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPlay->setIcon(icon2);
        actionDelete = new QAction(MainWindow);
        actionDelete->setObjectName(QString::fromUtf8("actionDelete"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/icons8-trash-24.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDelete->setIcon(icon3);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 10, 5, 1, 1);

        pauseButton = new QPushButton(centralwidget);
        pauseButton->setObjectName(QString::fromUtf8("pauseButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pauseButton->sizePolicy().hasHeightForWidth());
        pauseButton->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(pauseButton, 1, 0, 1, 1);

        fileCalender = new QCalendarWidget(centralwidget);
        fileCalender->setObjectName(QString::fromUtf8("fileCalender"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(fileCalender->sizePolicy().hasHeightForWidth());
        fileCalender->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(fileCalender, 3, 5, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 10, 3, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

        gridLayout_2->addLayout(gridLayout, 13, 5, 1, 1);

        clearTimerButton = new QPushButton(centralwidget);
        clearTimerButton->setObjectName(QString::fromUtf8("clearTimerButton"));
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(clearTimerButton->sizePolicy().hasHeightForWidth());
        clearTimerButton->setSizePolicy(sizePolicy3);

        gridLayout_2->addWidget(clearTimerButton, 0, 2, 1, 1);

        startButton = new QPushButton(centralwidget);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        sizePolicy3.setHeightForWidth(startButton->sizePolicy().hasHeightForWidth());
        startButton->setSizePolicy(sizePolicy3);

        gridLayout_2->addWidget(startButton, 0, 0, 1, 1);

        stopButton = new QPushButton(centralwidget);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));
        sizePolicy1.setHeightForWidth(stopButton->sizePolicy().hasHeightForWidth());
        stopButton->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(stopButton, 2, 0, 1, 1);

        lcdNumber = new QLCDNumber(centralwidget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(lcdNumber->sizePolicy().hasHeightForWidth());
        lcdNumber->setSizePolicy(sizePolicy4);
        lcdNumber->setMaximumSize(QSize(16777208, 16777206));
        lcdNumber->setAutoFillBackground(false);
        lcdNumber->setFrameShape(QFrame::Box);
        lcdNumber->setLineWidth(3);

        gridLayout_2->addWidget(lcdNumber, 0, 5, 3, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 677, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        audio_playback_bar = new QToolBar(MainWindow);
        audio_playback_bar->setObjectName(QString::fromUtf8("audio_playback_bar"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(audio_playback_bar->sizePolicy().hasHeightForWidth());
        audio_playback_bar->setSizePolicy(sizePolicy5);
        MainWindow->addToolBar(Qt::BottomToolBarArea, audio_playback_bar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionSet_Directory);
        audio_playback_bar->addAction(actionPlay);
        audio_playback_bar->addAction(actionPause);
        audio_playback_bar->addAction(actionStop);
        audio_playback_bar->addSeparator();
        audio_playback_bar->addAction(actionDelete);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionSet_Directory->setText(QCoreApplication::translate("MainWindow", "Set Directory", nullptr));
        actionPause->setText(QCoreApplication::translate("MainWindow", "Pause ", nullptr));
        actionStop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        actionPlay->setText(QCoreApplication::translate("MainWindow", "Play", nullptr));
        actionDelete->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        pauseButton->setText(QCoreApplication::translate("MainWindow", "Pause/Resume", nullptr));
        clearTimerButton->setText(QCoreApplication::translate("MainWindow", "Clear Timer ", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "Start Record", nullptr));
        stopButton->setText(QCoreApplication::translate("MainWindow", "Stop Record", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "Options", nullptr));
        audio_playback_bar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar_2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
