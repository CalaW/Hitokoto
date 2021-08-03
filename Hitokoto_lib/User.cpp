#include <memory>
#include "EncryptStrategy.h"
#include "User.h"

const std::shared_ptr<EncryptStrategy> encrypt_strategy(new Md5Strategy());

