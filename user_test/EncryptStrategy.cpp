#include <string>
#include <utility>
#include "EncryptStrategy.h"
#include "Md5.h"

using std::string;

// string&& Md5Strategy::encrypt(const string& src) {
//     return std::move(MD5(src).hexdigest());
// }

string Md5Strategy::encrypt(const string& src) {
    return MD5(src).hexdigest();
}