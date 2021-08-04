#ifndef ADMINUSER_H
#define ADMINUSER_H

#include "User.cpp"

using std::string;

class AdminUser : public User {
public:
    bool isAdmin() const override;
    void AddTrivialUser(const string& usrname, const string& pwd);
    void AddAdminUser(const string& pwd = default_pwd);
private:
    static string default_pwd;
    static AdminUser* instance;
    AdminUser(const string& pwd);
};

#endif /* ADMINUSER_H */