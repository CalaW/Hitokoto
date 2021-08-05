#ifndef ADMINUSER_H
#define ADMINUSER_H

#include "User.h"
#include "TrivialUser.h"

using std::string;

class AdminUser : public User {
public:
    AdminUser(const AdminUser&) = delete;
    AdminUser& operator=(const AdminUser&) = delete;
    bool isAdmin() const override;
    void addTrivialUser(const string& usrname, const string& pwd);
    static void addAdminUser(const string& pwd = default_pwd);
    static void addAdminUser(const Cipher& pwd);
    ~AdminUser();
private:
    static string default_pwd;
    static AdminUser* instance;
    AdminUser(const string& pwd);
    AdminUser(const Cipher& pwd);
};

#endif /* ADMINUSER_H */