#ifndef TRIVIALUSER_H
#define TRIVIALUSER_H

#include <string>
#include "User.h"

using std::string;

class TrivialUser : public User {
public:
    bool isAdmin() const override;
private:
    TrivialUser(const string& name, const string& pwd);
    TrivialUser(const string& name, const Cipher& pwd);

    friend class AdminUser;
    friend class User;
};

#endif /* TRIVIALUSER_H */
