#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include "logincontroller.h"

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();
    User* getLoginUserPtr();

signals:
    void loginSuccess(const LoginController&);

private slots:
    void on_LoginButton_clicked();
    void showLoginDialog();

private:
    Ui::LoginDialog *ui;
    LoginController login_ctrl;
};

#endif // LOGINDIALOG_H
