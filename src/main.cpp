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

    const db_health::HealthCheckResult result = db_health::checkTableHealth(tableName);

    if (result.healthy) {
        std::cout << "Health check result: OK" << std::endl;
    } else {
        std::cout << "Health check result: NG" << std::endl;
    }

    std::cout << "Message: " << result.message << std::endl;

    return result.healthy ? 0 : 2;
}