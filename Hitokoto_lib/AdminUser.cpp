#include "AdminUser.h"

AdminUser* AdminUser::instance = nullptr;

bool AdminUser::isAdmin() const {return true;}