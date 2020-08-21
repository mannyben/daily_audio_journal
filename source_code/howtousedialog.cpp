#include "howtousedialog.h"
#include "ui_howtousedialog.h"

HowtoUseDialog::HowtoUseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HowtoUseDialog)
{
    ui->setupUi(this);
}

HowtoUseDialog::~HowtoUseDialog()
{
    delete ui;
}
