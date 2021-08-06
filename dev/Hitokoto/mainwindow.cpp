#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_logoutBtn_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("Logout confirm"), tr("Are you sure to logout?"), QMessageBox::Yes|QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        this->hide();
        emit userLogout();
    }
}

void MainWindow::loginDialogSuccess(User* user) {
    this->show();
}

