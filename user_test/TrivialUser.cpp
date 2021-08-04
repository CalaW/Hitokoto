#include "User.h"
#include "TrivialUser.h"

TrivialUser::TrivialUser(const string& name, const string& pwd) 
: User(name, pwd) {}

bool TrivialUser::isAdmin() const {return false;}