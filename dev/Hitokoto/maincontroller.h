#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include "User.h"
#include <QString>

class MainController
{
public:
    MainController();
    QString getUserName();
    void setUserPtr(User* user);
    bool isLogined() const;
    bool isAdminLogined() const;
private:
    User* current_user;
};

#endif // MAINCONTROLLER_H
