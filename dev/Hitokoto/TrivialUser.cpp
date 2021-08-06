#include "User.h"
#include "TrivialUser.h"

TrivialUser::TrivialUser(const string& name, const string& pwd) 
: User(name, pwd) {}

TrivialUser::TrivialUser(const string& name, const Cipher& pwd) 
: User(name, pwd) {}

TrivialUser::~TrivialUser() {}

bool TrivialUser::isAdmin() const {return false;}