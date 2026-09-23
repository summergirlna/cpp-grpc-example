//
// Created by kuritayu on 2026/09/23.
//
#pragma once
#include <string>

namespace db_health::domain {

struct HealthCheckResult {
    bool healthy;
    std::string message;
};
}  // namespace db_health::domain
