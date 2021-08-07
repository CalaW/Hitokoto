#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "User.h"
#include "maincontroller.h"
#include "logincontroller.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void mainLoginBtnClicked();
    void userLogout();

private slots:
    void loginDialogSuccess(const LoginController&);
    void on_logioBtn_clicked();

private:
    Ui::MainWindow *ui;
    MainController main_ctrl;
};
#endif // MAINWINDOW_H
