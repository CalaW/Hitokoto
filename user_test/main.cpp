#include <iostream>
#include "User.h"
#include "AdminUser.h"
#include "TrivialUser.h"

int main()
{
    AdminUser::AddAdminUser();
    User* current_usr;
    try {
        current_usr = User::verify("Admin", "Admin");
        std::cout << "Admin login success" << std::endl;
    }
    catch(const std::exception& e) { std::cerr << e.what() << '\n'; return 0; }
    try { dynamic_cast<AdminUser*>(current_usr)->AddTrivialUser("ada","123"); }
    catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
    try { dynamic_cast<AdminUser*>(current_usr)->AddTrivialUser("ada","234"); }
    catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
    try { current_usr = User::verify("ada", "234"); }
    catch(const std::exception& e) { std::cerr << e.what() << '\n';}
    try {
        current_usr = User::verify("ada", "123");
        std::cout << current_usr->getName() << " login success" << std::endl;
    }
    catch(const std::exception& e) { std::cerr << e.what() << '\n';}
        std::cout << *current_usr << std::endl;
    try { 
        AdminUser* notwork = static_cast<AdminUser*>(current_usr);
        std::cout << "address: " << notwork << std::endl;
        notwork->AddTrivialUser("aaa","123");
    }
    catch(const std::exception& e) { std::cerr << e.what() << '\n'; }

    return 0;
}