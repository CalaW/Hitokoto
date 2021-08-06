#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "User.h"

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
    void userLogout();

private slots:
    void on_logoutBtn_clicked();
    void loginDialogSuccess(User*);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
