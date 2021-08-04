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
    void AddTrivialUser(const string& usrname, const string& pwd);
    static void AddAdminUser(const string& pwd = default_pwd);
    ~AdminUser();
private:
    static string default_pwd;
    static AdminUser* instance;
    AdminUser(const string& pwd);
};

#endif /* ADMINUSER_H */