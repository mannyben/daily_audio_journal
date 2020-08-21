/********************************************************************************
** Form generated from reading UI file 'directorysetdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIRECTORYSETDIALOG_H
#define UI_DIRECTORYSETDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_DirectorySetDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QPushButton *okButton;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_3;
    QTextEdit *textEdit;
    QSpacerItem *verticalSpacer_4;

    void setupUi(QDialog *DirectorySetDialog)
    {
        if (DirectorySetDialog->objectName().isEmpty())
            DirectorySetDialog->setObjectName(QString::fromUtf8("DirectorySetDialog"));
        DirectorySetDialog->resize(400, 300);
        gridLayout = new QGridLayout(DirectorySetDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(DirectorySetDialog);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Liberation Sans"));
        font.setPointSize(18);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 2);

        okButton = new QPushButton(DirectorySetDialog);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        gridLayout->addWidget(okButton, 10, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 10, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 3, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 8, 0, 2, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 6, 0, 1, 1);

        textEdit = new QTextEdit(DirectorySetDialog);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy);

        gridLayout->addWidget(textEdit, 1, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 2, 0, 1, 1);


        retranslateUi(DirectorySetDialog);

        QMetaObject::connectSlotsByName(DirectorySetDialog);
    } // setupUi

    void retranslateUi(QDialog *DirectorySetDialog)
    {
        DirectorySetDialog->setWindowTitle(QCoreApplication::translate("DirectorySetDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("DirectorySetDialog", "Enter your directory path here: ", nullptr));
        okButton->setText(QCoreApplication::translate("DirectorySetDialog", "Ok", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DirectorySetDialog: public Ui_DirectorySetDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIRECTORYSETDIALOG_H
