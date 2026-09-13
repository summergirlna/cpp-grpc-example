#include <iostream>
#include <string>

#include "health_checker.h"

int main() {
    const std::string tableName = "users";

    std::cout << "Checking table health: " << tableName << std::endl;

    const bool healthy = checkTableHealth(tableName);

    if (healthy) {
        std::cout << "Health check result: OK" << std::endl;
    } else {
        std::cout << "Health check result: NG" << std::endl;
    }

    return 0;
}