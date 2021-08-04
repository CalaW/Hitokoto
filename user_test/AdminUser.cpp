#include "AdminUser.h"

string AdminUser::default_pwd = "Admin";

AdminUser* AdminUser::instance = nullptr;

bool AdminUser::isAdmin() const {return true;}

AdminUser::AdminUser(const string& pwd)
: User("Admin", pwd) {}

void AdminUser::AddTrivialUser(const string& usrname, const string& pwd) {
    new TrivialUser(usrname, pwd);
}

void AdminUser::AddAdminUser(const string& pwd) {
    if (instance == nullptr) {
        instance = new AdminUser(pwd);
    } else {
        throw std::invalid_argument("Two admin cannot exist at the same time!");
    }
}

AdminUser::~AdminUser() {
    if (instance) {delete instance;}
}