/**
 * @file TrivialUser.cpp
 * @author CalaW (maker_cc@foxmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-07
 * 
 * 
 */
#include "User.h"
#include "TrivialUser.h"

/**
 * @brief Construct a new Trivial User:: Trivial User object using plaintext
 * 
 * @param name 
 * @param pwd 
 */
TrivialUser::TrivialUser(const string& name, const string& pwd) 
: User(name, pwd) {}

/**
 * @brief Construct a new Trivial User:: Trivial User object using cipher
 * 
 * @param name 
 * @param pwd 
 */
TrivialUser::TrivialUser(const string& name, const Cipher& pwd) 
: User(name, pwd) {}

/**
 * @brief Destroy the Trivial User:: Trivial User object override
 * 
 */
TrivialUser::~TrivialUser() {}

/**
 * @brief Trivialuser isnot admin
 * 
 * @return true 
 * @return false 
 */
bool TrivialUser::isAdmin() const {return false;}