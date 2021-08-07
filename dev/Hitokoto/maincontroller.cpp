#include "maincontroller.h"
#include "Hitokoto.h"
#include <QApplication>
#include <QMessageBox>

MainController::MainController()
{
    Hitokoto::setDefaultPath(QApplication::applicationDirPath().toStdString() + "/../../../resource/hitokoto.txt");
    Hitokoto::loadFromFile();
}

QString MainController::getUserName() {
    if (current_user == nullptr) {
        return "unlogined user";
    } else {
        return QString::fromStdString(current_user->getName());
    }
}

void MainController::setUserPtr(User* user) {
    current_user = user;
}

bool MainController::isLogined() const {
    return current_user != nullptr;
}

bool MainController::isAdminLogined() const {
    return isLogined() && current_user->isAdmin();
}

void MainController::addUser(const QString &name, const QString &pwd) {
    try {
        current_user->addTrivialUser(name.toStdString(), pwd.toStdString());
    } catch (std::exception e) {
    } //TODO
}
