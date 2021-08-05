#include "AdminUser.h"

string AdminUser::default_pwd = "Admin";

AdminUser* AdminUser::instance = nullptr;

bool AdminUser::isAdmin() const {return true;}

AdminUser::AdminUser(const string& pwd) //TODO template
: User("Admin", pwd) {}

AdminUser::AdminUser(const Cipher& cipher_pwd)
: User("Admin", cipher_pwd) {}

void AdminUser::addTrivialUser(const string& usrname, const string& pwd) {
    if (this->isAdmin()) { //must called by an admin user
        new TrivialUser(usrname, pwd);
    } else {
        throw std::invalid_argument("Permission denied!");
    }
}

void AdminUser::addAdminUser(const string& cipher_pwd) { //TODO template
    if (instance == nullptr) {
        instance = new AdminUser(cipher_pwd);
    } else {
        throw std::invalid_argument("Two admin cannot exist at the same time!");
    }
}

void AdminUser::addAdminUser(const Cipher& cipher_pwd) {
    if (instance == nullptr) {
        instance = new AdminUser(cipher_pwd);
    } else {
        throw std::invalid_argument("Two admin cannot exist at the same time!");
    }
}

AdminUser::~AdminUser() {
    if (instance) {delete instance;}
}