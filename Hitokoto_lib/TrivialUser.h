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
};

#endif /* TRIVIALUSER_H */
