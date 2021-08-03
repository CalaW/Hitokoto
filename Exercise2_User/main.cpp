#include <iostream>
#include <exception>
#include "User.h"

int main(int argc, const char * argv[]) {
    try {
    bool IsAdded = false;
    std::cout << User::AddAdminUser();
    std::cout << User::AddAdminUser();
    std::cout << User::AddTrivialUser("1", "456");
    std::cout << User::AddTrivialUser("1", "567");
    std::cout << User::AddTrivialUser("2", "567");
    std::cout << User::AddTrivialUser("Admin", "567");
    std::cout << User::AddTrivialUser("", "567");
    std::cout << User::AddTrivialUser("aaa", "");
    } catch(const std::exception& e) {
        std::cerr << e.what();
    }

    Test test("1", "123");
    return 0;
}
