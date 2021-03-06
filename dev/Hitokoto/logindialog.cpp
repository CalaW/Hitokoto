/**
 * @file logindialog.cpp
 * @author CalaW (maker_cc@foxmail.com)
 * @brief login window
 * @version 0.1
 * @date 2021-08-07
 * 
 * auto generated by qt
 * 
 */
#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

/**
 * @brief slot to react to login button clicked
 * 
 */
void LoginDialog::on_LoginButton_clicked()
{
    QString name = ui->UsernameEdit->text().trimmed();
    QString pwd = ui->PasswordEdit->text();
    LoginResult ret = login_ctrl.Login(name, pwd);
    switch (ret) {
    case LoginResult::AdminLogin:
        QMessageBox::information(this, tr("login success"), tr("Admin user logined"), QMessageBox::Ok);
        emit loginSuccess(login_ctrl);
        accept(); break;
    case LoginResult::TrivialLogin:
        QMessageBox::information(this, tr("login success"), tr("User ") + name + tr(" logined"), QMessageBox::Ok);
        emit loginSuccess(login_ctrl);
        accept(); break;
    case LoginResult::UserDNE:
        QMessageBox::warning(this, tr("login failed"), tr("User does not exist!"), QMessageBox::Ok);
        break;
    case LoginResult::WrongPwd:
        QMessageBox::warning(this, tr("login failed"), tr("Wrong username or password!"), QMessageBox::Ok);
        break;
    }
        //reset
        ui->UsernameEdit->clear(); 
        ui->PasswordEdit->clear();
        ui->UsernameEdit->setFocus();
}

void LoginDialog::showLoginDialog() {
    this->show();
}
