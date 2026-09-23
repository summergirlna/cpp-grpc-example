//
// Created by kuritayu on 2026/09/23.
//
#pragma once
#include "domain/table_health_checker.h"

namespace db_health::infrastructure {

class MockTableHealthChecker final : public domain::TableHealthChecker {
public:
    [[nodiscard]] domain::HealthCheckResult check(const std::string& tableName) const override;
};
}  // namespace db_health::infrastructure
