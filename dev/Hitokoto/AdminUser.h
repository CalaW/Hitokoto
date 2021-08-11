/**
 * @file AdminUser.h
 * @brief Header of class AdminUser
 * @author CalaW (maker_cc@foxmail.com)
 * @date 2021-08-07
 * 
 * @history: I use git.
 */

#ifndef ADMINUSER_H
#define ADMINUSER_H

#include "User.h"
#include "TrivialUser.h"

using std::string;

/**
 * @class AdminUser
 * @brief Class AdminUser, inherit from abstract base class User
 * @interface isAdmin(), addAdminUser()
 * @author CalaW (maker_cc@foxmail.com)
 * @date 2021-08-07
 * 
 */
class AdminUser : public User {
public:
    AdminUser(const AdminUser&) = delete; //cannot copy admin
    AdminUser& operator=(const AdminUser&) = delete; //cannot copy admin
    bool isAdmin() const override; //AdminUser is admin

    //static method to add instance, assure only one instance exist
    static void addAdminUser(const string& pwd = m_strDefaultPwd);
    static void addAdminUser(const Cipher& pwd);

    ~AdminUser() override; //virtual destructor

private:
    static string m_strDefaultPwd; //default password of admin
    static AdminUser* s_pInstance; //single instance

    //private constructors
    AdminUser(const string& pwd);
    AdminUser(const Cipher& pwd);
};

#endif /* ADMINUSER_H */