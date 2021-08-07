#ifndef ADUSERMANDIALOG_H
#define ADUSERMANDIALOG_H

#include <QDialog>

namespace Ui {
class adUserManDialog;
}

class adUserManDialog : public QDialog
{
    Q_OBJECT

public:
    explicit adUserManDialog(QWidget *parent = nullptr);
    ~adUserManDialog();

private:
    Ui::adUserManDialog *ui;
};

#endif // ADUSERMANDIALOG_H
