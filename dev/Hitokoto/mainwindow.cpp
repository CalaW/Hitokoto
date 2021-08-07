#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "hitotablecontroller.h"
#include "dialognewhito.h"
#include "adnewuserdialog.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ui->newBtn->setEnabled(false);
    this->ui->adDelHitoBtn->hide();
    this->ui->adManageBtn->hide();
    ui->welcomeLabel->setText(tr("Welcome, ") + "<b>" + main_ctrl.getUserName() + "</b>");
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setModel(&hito_table_ctrl);
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
    QObject::connect(&dialog, SIGNAL(adAddUserConfirm(QString, QString)), this, SLOT(adNewUserDialogSuccess(QString, QString)));
    dialog.exec();
}

void MainWindow::adNewUserDialogSuccess(const QString& name, const QString& pwd) {
    main_ctrl.addUser(name, pwd);
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

