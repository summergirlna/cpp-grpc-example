//
// Created by kuritayu on 2026/09/13.
//

#include "health_checker.h"

namespace db_health {

    HealthCheckResult checkTableHealth(const std::string& tableName) {
        if (tableName.empty()) {
            return {
                false,
                "table name is empty"
            };
        }

        // todo テーブル名固定なのは修正する
        if (tableName == "users") {
            return {
                true,
                "table is readable"
            };
        }

        return {
            false,
            "table is not readable"
        };
    }
}
