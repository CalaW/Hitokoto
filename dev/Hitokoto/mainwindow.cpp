#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ui->newBtn->setCheckable(false);
    this->ui->adDelHitoBtn->hide();
    this->ui->adManageBtn->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loginDialogSuccess(const LoginController& login_ctrl) {
    main_ctrl.setUserPtr(login_ctrl.getLoginUserPtr());
    ui->welcomeLabel->setText(tr("Welcome, ") + main_ctrl.getUserName());
    if (main_ctrl.isAdminLogined()) {
        ui->adDelHitoBtn->show();
        ui->adManageBtn->show();
    }
    ui->logioBtn->setText(tr("Logout"));
    ui->newBtn->setCheckable(true);
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
            this->ui->newBtn->setCheckable(false);
            if (main_ctrl.isAdminLogined()) {
                this->ui->adDelHitoBtn->hide();
                this->ui->adManageBtn->hide();
            }
            main_ctrl.setUserPtr(nullptr);
            ui->welcomeLabel->setText(main_ctrl.getUserName());
            emit userLogout();
        }
    }
}

