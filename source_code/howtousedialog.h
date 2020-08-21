#ifndef HOWTOUSEDIALOG_H
#define HOWTOUSEDIALOG_H

#include <QDialog>

namespace Ui {
class HowtoUseDialog;
}

class HowtoUseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HowtoUseDialog(QWidget *parent = nullptr);
    ~HowtoUseDialog();

private:
    Ui::HowtoUseDialog *ui;
};

#endif // HOWTOUSEDIALOG_H
