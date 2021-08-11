/**
 * @file maincontroller.h
 * @author CalaW (maker_cc@foxmail.com)
 * @brief controller of main window
 * @version 0.1
 * @date 2021-08-07
 * 
 * 
 */
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
    bool addUser(const QString& name, const QString& pwd);
    bool deleteUser(const QString& name);
    bool adChangeUserPwd(const QString& name, const QString& pwd);
    bool changePwd(const QString& prevPwd, const QString& newPwd);

private:
    User* m_pCurrentUser;
};

#endif // MAINCONTROLLER_H
