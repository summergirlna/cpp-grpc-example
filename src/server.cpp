//
// Created by kuritayu on 2026/09/22.
//

#include <grpcpp/grpcpp.h>

#include "app/check_table_health_use_case.h"
#include "db_health.grpc.pb.h"
#include "infrastructure/mock_table_health_checker.h"

class DbHealthServiceImpl final : public db_health::DbHealthService::Service {
public:
    explicit DbHealthServiceImpl(
        const db_health::app::CheckTableHealthUseCase& checkTableHealthUseCase)
        : checkTableHealthUseCase_(&checkTableHealthUseCase) {}

    grpc::Status CheckTableHealth(grpc::ServerContext* context,
                                  const db_health::CheckTableHealthRequest* request,
                                  db_health::CheckTableHealthResponse* response) override {
        const db_health::domain::HealthCheckResult result =
            checkTableHealthUseCase_->execute(request->table_name());

        response->set_healthy(result.healthy);
        response->set_message(result.message);

        return grpc::Status::OK;
    }

private:
    const db_health::app::CheckTableHealthUseCase* checkTableHealthUseCase_;
};

void runServer() {
    const std::string serverAddress = "0.0.0.0:50051";

    db_health::infrastructure::MockTableHealthChecker tableHealthChecker;
    db_health::app::CheckTableHealthUseCase useCase(tableHealthChecker);
    DbHealthServiceImpl service(useCase);

    grpc::ServerBuilder builder;
    builder.AddListeningPort(serverAddress, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());

    std::cout << "Server listening on " << serverAddress << '\n';

    server->Wait();
}

int main() {
    runServer();
    return 0;
}