#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "User.h"
#include "maincontroller.h"
#include "logincontroller.h"
#include "hitotablecontroller.h"

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
    void adAddUserDialogSuccess(const QString& name, const QString& pwd);
    void adDelUserDialogSuccess(const QString& name);
    void adChUserPwdDialogSuccess(const QString& name, const QString& pwd);
    void changePwdDialogSuccess(const QString& prevPwd, const QString& newPwd);

    void on_logioBtn_clicked();

    void on_newBtn_clicked();

    void on_adManageBtn_clicked();

    void on_timeRangeCheck_stateChanged(int arg1);

    void on_fromTimeEdt_dateTimeChanged(const QDateTime &dateTime);

    void on_toTimeEdt_dateTimeChanged(const QDateTime &dateTime);

    void on_changePwdBtn_clicked();

private:
    Ui::MainWindow *ui;
    MainController main_ctrl;
    HitoTableController hito_table_ctrl;
};
#endif // MAINWINDOW_H
