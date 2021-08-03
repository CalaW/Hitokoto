#ifndef USER_H
#define USER_H

#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <exception>
#include <memory>
#include "EncryptStrategy.h"
#include "Cipher.h"

using std::string;
using std::map;
using std::ostream;

class User {
public:
    User() = delete; //can't construct user without name and pwd
    User(const User&) = delete; //can't copy user
    User& operator=(const User&) = delete; //can't copy user

    static bool verify(const string& name, const string& pwd);
    static void loadFromFile(const string& path);
    static void saveToFile(const string& path);

    inline const string& const getName();
    virtual bool isAdmin() const = 0;
    void changePwd(const string& plain);
    friend ostream& operator<<(ostream& out, const User& src);

    static const std::shared_ptr<EncryptStrategy> encrypt_strategy;

private:
    string name;
    Cipher cipher_pwd;
    static map<string, User*> user_map;
};

#endif /* USER_H */