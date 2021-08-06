#include "mainwindow.h"
#include "logindialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow main_window;
    LoginDialog login_dialog;

    login_dialog.show();

    QObject::connect(&login_dialog, SIGNAL(loginSuccess(User*)), &main_window, SLOT(loginDialogSuccess(User*)));
    QObject::connect(&main_window, SIGNAL(userLogout()), &login_dialog, SLOT(mainLogout()));


//    if (login_dialog.exec() == QDialog::Accepted) {
//        main_window.show();
    return a.exec();
}
