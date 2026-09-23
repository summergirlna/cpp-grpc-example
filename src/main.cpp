#include <iostream>
#include <string>

#include "app/check_table_health_use_case.h"
#include "infrastructure/mock_table_health_checker.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <table_name>" << '\n';
        return 1;
    }

    const std::string tableName = argv[1];

    db_health::infrastructure::MockTableHealthChecker tableHealthChecker;
    const db_health::app::CheckTableHealthUseCase useCase(tableHealthChecker);

    std::cout << "Checking table health: " << tableName << '\n';

    const db_health::domain::HealthCheckResult result = useCase.execute(tableName);

    if (result.healthy) {
        std::cout << "Health check result: OK" << '\n';
    } else {
        std::cout << "Health check result: NG" << '\n';
    }

    std::cout << "Message: " << result.message << '\n';

    return result.healthy ? 0 : 2;
}
