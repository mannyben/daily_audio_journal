#ifndef DIRECTORYSETDIALOG_H
#define DIRECTORYSETDIALOG_H

#include <QDialog>

namespace Ui {
class DirectorySetDialog;
}

class DirectorySetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DirectorySetDialog(QWidget *parent = nullptr);
    ~DirectorySetDialog();
    QString directoryText;
    void formatSlashesText(QString&);

private slots:
    void on_textEdit_textChanged();

    void on_okButton_clicked();

private:
    Ui::DirectorySetDialog *ui;
};

#endif // DIRECTORYSETDIALOG_H
