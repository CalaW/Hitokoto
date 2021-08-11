/**
 * @file AdminUser.cpp
 * @author CalaW (maker_cc@foxmail.com)
 * @brief Implementation of AdminUser class
 * @version 0.1
 * @date 2021-08-07
 * 
 * @history: I use git.
 */

#include "AdminUser.h"

//static member init begin

string AdminUser::m_strDefaultPwd = "Admin";
AdminUser* AdminUser::s_pInstance = nullptr;

//static member init end

/**
 * @name isAdmin
 * @brief virtual function to verify user is/isn't admin
 * 
 * @retval true 
 * @retval false 
 */
bool AdminUser::isAdmin() const {return true;}

/**
 * @name AdminUser
 * @brief Construct a new Admin User object using plaintext
 * 
 * will call User's constructor and add instance to user_map
 * 
 * @param pwd plaintext password, default="Admin"
 */
AdminUser::AdminUser(const string& pwd) 
: User("Admin", pwd) {}

/**
 * @name AdminUser
 * @brief Construct a new Admin User object using ciphertext
 * 
 * will call User's constructor and add instance to user_map
 * 
 * @param cipher_pwd cipher text password
 */
AdminUser::AdminUser(const Cipher& cipher_pwd)
: User("Admin", cipher_pwd) {}

/**
 * @name addAdminUser
 * @brief add an adminuser from plaintext, assure only one instance exists
 * 
 * @param pwd plaintext password
 * @exception invalid_argument Two admin exist at the same time
 */
void AdminUser::addAdminUser(const string& pwd) {
    if (s_pInstance == nullptr) {
        s_pInstance = new AdminUser(pwd);
    } else {
        throw std::invalid_argument("Two admin cannot exist at the same time!");
    }
}

/**
 * @name addAdminUser
 * @brief add an adminuser from ciphertext, assure only one instance exists
 * 
 * @param cipher_pwd plaintext password
 * @exception invalid_argument Two admin exist at the same time
 */
void AdminUser::addAdminUser(const Cipher& cipher_pwd) {
    if (s_pInstance == nullptr) {
        s_pInstance = new AdminUser(cipher_pwd);
    } else {
        throw std::invalid_argument("Two admin cannot exist at the same time!");
    }
}

/**
 * @name ~AdminUser
 * @brief Destroy the Admin User object
 * 
 */
AdminUser::~AdminUser() {
    // only can be called by delete s_pInstance
    if (s_pInstance == nullptr) {
        addAdminUser();
        //should not happen
        //instance will be removed from user_map by User destructor
    }
}