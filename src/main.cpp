#include <iostream>
#include <string>

#include "health_checker.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <table_name>" << std::endl;
        return 1;
    }

    const std::string tableName = argv[1];

    std::cout << "Checking table health: " << tableName << std::endl;

    const bool healthy = checkTableHealth(tableName);

    if (healthy) {
        std::cout << "Health check result: OK" << std::endl;
    } else {
        std::cout << "Health check result: NG" << std::endl;
    }

    return healthy ? 0 : 2;
}