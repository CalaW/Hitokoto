#include <iostream>
#include "User.h"
#include "AdminUser.h"
#include "TrivialUser.h"

int main()
{
    User::loadFromFile("user.txt");
    User* current_usr;
    // try {
    //     current_usr = User::verify("Admin", "Admin");
    //     std::cout << "Admin login success" << std::endl;
    //     current_usr->changePwd("hahaha");
    // }
    // catch(const std::exception& e) { std::cerr << e.what() << '\n'; return 0; }
    // try { dynamic_cast<AdminUser*>(current_usr)->addTrivialUser("ada","123"); }
    // catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
    // try { dynamic_cast<AdminUser*>(current_usr)->addTrivialUser("ada","234"); }
    // catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
    // try { current_usr = User::verify("ada", "234"); }
    // catch(const std::exception& e) { std::cerr << e.what() << '\n';}
    // try {
    //     current_usr = User::verify("ada", "123");
    //     std::cout << current_usr->getName() << " login success" << std::endl;
    // }
    // catch(const std::exception& e) { std::cerr << e.what() << '\n';}
    //     std::cout << *current_usr << std::endl;
    // try { 
    //     AdminUser* notwork = static_cast<AdminUser*>(current_usr);
    //     std::cout << "address: " << notwork << std::endl;
    //     notwork->addTrivialUser("aaa","123");
    // }
    // catch(const std::exception& e) { std::cerr << e.what() << '\n'; }

    current_usr = nullptr;
    while (true) {
        try
        {
            string operation;
            std::cin >> operation;
            if (operation == "login") {
                string name, pwd;
                std::cin >> name >> pwd;
                current_usr = User::verify(name, pwd);
                std::cout << current_usr->getName() << " login success!" << std::endl;
            } else if (operation == "quit") {
                break;
            } else if (current_usr != nullptr) {
                if (operation == "add") {
                    string name, pwd;
                    std::cin >> name >> pwd;
                    static_cast<AdminUser*>(current_usr)->addTrivialUser(name, pwd);
                    std::cout << current_usr->getName() << " add user " << name << std::endl;
                } else if (operation == "changePwd") {
                    string pwd;
                    std::cin >> pwd;
                    current_usr->changePwd(pwd);
                    std::cout << current_usr->getName() << " change password" << std::endl;
                } else if (operation == "logout") {
                    std::cout << current_usr->getName() << " log out" << std::endl;
                    current_usr = nullptr;
                }
            } else {
                throw std::invalid_argument("Please login!");
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }


    User::saveToFile("user.txt");

    return 0;
}