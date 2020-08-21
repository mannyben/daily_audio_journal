#include "directorysetdialog.h"
#include "ui_directorysetdialog.h"

DirectorySetDialog::DirectorySetDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DirectorySetDialog)
{
    ui->setupUi(this);

    directoryText = "";
}

DirectorySetDialog::~DirectorySetDialog()
{
    delete ui;
}

void DirectorySetDialog::on_textEdit_textChanged()
{
    directoryText = ui->textEdit->toPlainText();
    formatSlashesText(directoryText);
}

void DirectorySetDialog::on_okButton_clicked()
{
    this->close();
}

void DirectorySetDialog::formatSlashesText(QString &text) {

    for (auto c : text)
        if ( c == '\'')
            c = '/';

}
