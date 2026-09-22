//
// Created by kuritayu on 2026/09/22.
//

#include <grpcpp/grpcpp.h>

#include "db_health.grpc.pb.h"

class DbHealthClient {
public:
    explicit DbHealthClient(const std::shared_ptr<grpc::Channel>& channel)
        : stub_(db_health::DbHealthService::NewStub(channel)) {}

    db_health::CheckTableHealthResponse CheckTableHealth(const std::string& tableName) {
        db_health::CheckTableHealthRequest request;
        request.set_table_name(tableName);

        db_health::CheckTableHealthResponse response;
        grpc::ClientContext context;

        const grpc::Status status = stub_->CheckTableHealth(&context, request, &response);

        if (!status.ok()) {
            response.set_healthy(false);
            response.set_message("gRPC request failed: " + status.error_message());
        }

        return response;
    }

private:
    std::unique_ptr<db_health::DbHealthService::Stub> stub_;
};

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <table_name>" << '\n';
        return 1;
    }

    const std::string tableName = argv[1];
    const std::string serverAddress = "localhost:50051";

    DbHealthClient client(grpc::CreateChannel(serverAddress, grpc::InsecureChannelCredentials()));

    const db_health::CheckTableHealthResponse response = client.CheckTableHealth(tableName);

    std::cout << "Request table: " << tableName << '\n';

    if (response.healthy()) {
        std::cout << "Health check result: OK" << '\n';
    } else {
        std::cout << "Health check result: NG" << '\n';
    }

    std::cout << "Message: " << response.message() << '\n';

    return response.healthy() ? 0 : 2;
}