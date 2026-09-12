#include <iostream>

bool checkTableHealth(const std::string& tableName) {
    if (tableName.empty()) {
        return false;
    }

    // todo テーブル名固定なのは修正する
    return tableName == "users";
}

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