#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "hitotablecontroller.h"
#include "dialognewhito.h"
#include "adnewuserdialog.h"
#include "changepwddialog.h"
#include <QMessageBox>
#include <QIcon>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ui->newBtn->setEnabled(false);
    this->ui->changePwdBtn->setEnabled(false);
    this->ui->adDelHitoBtn->hide();
    this->ui->adManageBtn->hide();
    ui->welcomeLabel->setText(tr("Welcome, ") + "<b>" + main_ctrl.getUserName() + "</b>");
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableView->setModel(&hito_table_ctrl);
    this->setWindowTitle(tr("Hitokoto·一言一行一念"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loginDialogSuccess(const LoginController& login_ctrl) {
    main_ctrl.setUserPtr(login_ctrl.getLoginUserPtr());
    ui->welcomeLabel->setText(tr("Welcome, ") + "<b>" + main_ctrl.getUserName() + "</b>");
    if (main_ctrl.isAdminLogined()) {
        ui->adDelHitoBtn->show();
        ui->adManageBtn->show();
    }
    ui->logioBtn->setText(tr("Logout"));
    ui->newBtn->setEnabled(true);
    ui->changePwdBtn->setEnabled(true);
    this->show();
}

void MainWindow::on_logioBtn_clicked() {
    if (!main_ctrl.isLogined()) {
        emit mainLoginBtnClicked();
    } else if (main_ctrl.isLogined()) {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, tr("Logout confirm"), tr("Are you sure to logout?"), QMessageBox::Yes|QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            this->ui->logioBtn->setText(tr("Login"));
            this->ui->newBtn->setEnabled(false);
            this->ui->changePwdBtn->setEnabled(false);
            if (main_ctrl.isAdminLogined()) {
                this->ui->adDelHitoBtn->hide();
                this->ui->adManageBtn->hide();
            }
            main_ctrl.setUserPtr(nullptr);
            ui->welcomeLabel->setText(tr("Welcome, ") + "<b>" + main_ctrl.getUserName() + "</b>");
            emit userLogout();
        }
    }
}


void MainWindow::on_newBtn_clicked()
{
//    if (DialogNewHito().exec() == QDialog::Accepted) {
//    }
    DialogNewHito().exec();
}


void MainWindow::on_adManageBtn_clicked()
{
    adNewUserDialog dialog(this);
    QObject::connect(&dialog, SIGNAL(adAddUserConfirm(QString, QString))
                     , this, SLOT(adAddUserDialogSuccess(QString, QString)));
    QObject::connect(&dialog, SIGNAL(adDelUserConfirm(QString))
                     , this, SLOT(adDelUserDialogSuccess(QString)));
    QObject::connect(&dialog, SIGNAL(adChUserPwdConfirm(QString, QString))
                     , this, SLOT(adChUserPwdDialogSuccess(QString, QString)));
    dialog.exec();
}

void MainWindow::adAddUserDialogSuccess(const QString& name, const QString& pwd) {
    int result = main_ctrl.addUser(name, pwd);
    switch (result) {
    case true:
        QMessageBox::information(this, tr("User Added"), "User \"" + name + "\" added");
        break;
    case false:
        QMessageBox::warning(this, tr("Warning"), "User \"" + name + "\" duplicate!");
        break;
    default: break;
    }
}

void MainWindow::adDelUserDialogSuccess(const QString& name) {
    int result = main_ctrl.deleteUser(name);
    switch (result) {
    case true:
        QMessageBox::information(this, tr("Success"), "User \"" + name + "\" deleted.");
        break;
    case false:
        QMessageBox::warning(this, tr("Warning"), "User \"" + name + "\"not found!");
        break;
    default: break;
    }
}

void MainWindow::adChUserPwdDialogSuccess(const QString& name, const QString& pwd) {
    int result = main_ctrl.adChangeUserPwd(name, pwd);
    switch (result) {
    case true:
        QMessageBox::information(this, tr("Success"), "User \"" + name + "\" password changed.");
        break;
    case false:
        QMessageBox::warning(this, tr("Warning"), "User \"" + name + "\"not found!");
        break;
    default: break;
    }
}

void MainWindow::changePwdDialogSuccess(const QString& prevPwd, const QString& newPwd) {
    int result = main_ctrl.changePwd(prevPwd, newPwd);
    switch (result) {
    case true:
        QMessageBox::information(this, tr("success"), tr("Password Changed."));
        break;
    case false:
        QMessageBox::warning(this, tr("Warning"), tr("Previous password incorrect!"));
        break;
    default: break;
    }
}

void MainWindow::on_timeRangeCheck_stateChanged(int arg1)
{
    hito_table_ctrl.setViewByRange(arg1);
    if (arg1) {
        ui->fromTimeEdt->setEnabled(true);
        ui->toTimeEdt->setEnabled(true);
        ui->toTimeEdt->setDateTime(QDateTime::currentDateTime());
    } else {
        ui->fromTimeEdt->setEnabled(false);
        ui->toTimeEdt->setEnabled(false);
    }
}


void MainWindow::on_fromTimeEdt_dateTimeChanged(const QDateTime &dateTime)
{
    hito_table_ctrl.setStartTime(dateTime.toSecsSinceEpoch());
}


void MainWindow::on_toTimeEdt_dateTimeChanged(const QDateTime &dateTime)
{
    hito_table_ctrl.setEndTime(dateTime.toSecsSinceEpoch());
}


void MainWindow::on_changePwdBtn_clicked()
{
    ChangePwdDialog dialog(this);
    QObject::connect(&dialog, SIGNAL(changePwdConfirm(QString, QString))
                     , this, SLOT(changePwdDialogSuccess(QString, QString)));
    dialog.exec();
}

