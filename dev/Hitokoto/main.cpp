#include "mainwindow.h"
#include "logindialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow main_window;
    LoginDialog login_dialog;

    if (login_dialog.exec() == QDialog::Accepted) {
        main_window.show();
        return a.exec();
    }
    return 0;
}
