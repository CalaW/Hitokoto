#include "maincontroller.h"

MainController::MainController()
{

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
