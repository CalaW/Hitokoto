#include <memory>
#include <exception>
#include <fstream>
#include "EncryptStrategy.h"
#include "User.h"
#include "AdminUser.h"
#include "TrivialUser.h"

using std::pair;
using std::map;
using std::string;
using std::ostream;

map<string, User*> User::user_map{};
string User::default_path = "user.txt";
const std::shared_ptr<EncryptStrategy> User::encrypt_str(new Md5Strategy());

User::Service User::service {};

User* User::verify(const string& name, const string& pwd) {
    auto it = user_map.find(name);
    if (it == user_map.end()) {
        throw std::invalid_argument("User does not exist!");
    } else if (it->second->cipher_pwd != pwd) {
        throw std::invalid_argument("Wrong user name or password!");
    }
    return it->second;
}

User::User(const string& usrname, const string& pwd)
: name(usrname), cipher_pwd(pwd, encrypt_str.get()) {
    if (usrname.empty() || pwd.empty()) {
        throw std::invalid_argument("Cannot use empty user name or password!");
    }
    auto result = user_map.insert({usrname, this});
    if(!result.second) {
        throw std::invalid_argument("Duplicate user name!");
    }
}

User::User(const string& usrname, const Cipher& pwd)
: name(usrname), cipher_pwd(pwd) {
    if (usrname.empty()) {
        throw std::invalid_argument("Cannot use empty user name");
    }
    auto result = user_map.insert({usrname, this});
    if(!result.second) {
        throw std::invalid_argument("Duplicate user name!");
    }
}

User::~User() {
    user_map.erase(name);
}

void User::loadFromFile(const string& path) {
    std::ifstream user_file(path);
    if (!user_file.is_open()) {
        throw std::invalid_argument("Cannot open file \"" + path + "\"");
    }
    while (user_file.peek() != EOF) {
        string name;
        string pwd;
        // user_file >> name >> pwd;
        std::getline(user_file, name);
        std::getline(user_file, pwd);
        if (name == "Admin") {
            AdminUser::addAdminUser(Cipher::makeFromCipher(pwd, encrypt_str.get()));
        } else {
            new TrivialUser(name, Cipher::makeFromCipher(pwd, encrypt_str.get()));
        }
    }
    if (user_map.empty() || user_map.count("Admin") == 0) {
        AdminUser::addAdminUser();
    }
}

void User::saveToFile(const string& path) {
    std::ofstream user_file(path);
    if (!user_file.is_open()) {
        throw std::invalid_argument("Cannot create file \"" + path + "\"");
    }
    for (const auto& it : user_map) {
        user_file << *it.second;
    }
}

void User::setDefaultPath(const string &path) {
    default_path = path;
}

void User::changePwd(const string& plain) {
    cipher_pwd.update(plain);
}

void User::addTrivialUser(const string& usrname, const string& pwd) {
    if (this->isAdmin()) { //must called by an admin user
        new TrivialUser(usrname, pwd);
    } else {
        throw std::invalid_argument("Permission denied!");
    }
}

void User::deleteTrivialUser(const string& usrname) {
    if (this->isAdmin()) {
        auto it = user_map.find(usrname);
        if (it == user_map.end()) {
            throw std::invalid_argument("User \"" + usrname + "\" does not exist");
        } else {
            delete (*it).second;
        }
    } else {
        throw std::invalid_argument("Permission denied!");
    }
}

ostream& operator<<(ostream& out, const User& src) {
    out << src.name << "\n" << src.cipher_pwd << std::endl;
    return out;
}

User::Service::Service() {
#ifdef AutoLoadUsrList
    User::loadFromFile(default_path);
#endif
}

User::Service::~Service() {
#ifdef AutoSaveUsrList
    User::saveToFile(default_path);
#endif
    for (auto it = user_map.begin(); it != user_map.end();) {
        delete (*(it++)).second;
    }
}
