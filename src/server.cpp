//
// Created by kuritayu on 2026/09/22.
//

#include <grpcpp/grpcpp.h>

#include "db_health.grpc.pb.h"
#include "health_checker.h"

class DbHealthServiceImpl final : public db_health::DbHealthService::Service {
public:
    grpc::Status CheckTableHealth(
        grpc::ServerContext* context,
        const db_health::CheckTableHealthRequest* request,
        db_health::CheckTableHealthResponse* response
        ) override {
        const db_health::HealthCheckResult result = db_health::checkTableHealth(request->table_name());

        response->set_healthy(result.healthy);
        response->set_message(result.message);

        return grpc::Status::OK;
    }
};

void runServer() {
    const std::string serverAddress = "0.0.0.0:50051";

    DbHealthServiceImpl service;

    grpc::ServerBuilder builder;
    builder.AddListeningPort(serverAddress, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());

    std::cout << "Server listening on " << serverAddress << std::endl;

    server->Wait();
}

int main() {
    runServer();
    return 0;
}