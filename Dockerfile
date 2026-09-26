FROM ubuntu:24.04 AS builder

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    cmake \
    git \
    pkg-config \
    libprotobuf-dev \
    protobuf-compiler \
    libgrpc++-dev \
    protobuf-compiler-grpc \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY . .

RUN mkdir -p generated \
    && protoc --cpp_out=generated --proto_path=proto proto/db_health.proto \
    && protoc --proto_path=proto \
        --grpc_out=generated \
        --plugin=protoc-gen-grpc=/usr/bin/grpc_cpp_plugin \
        proto/db_health.proto

RUN cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
RUN cmake --build build --parallel

FROM ubuntu:24.04 AS runtime-base

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y --no-install-recommends \
    libprotobuf-dev \
    libgrpc++1.51 \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

FROM runtime-base AS server-runtime

COPY --from=builder /app/build/db_health_server /app/db_health_server

EXPOSE 50051

CMD ["/app/db_health_server"]

FROM runtime-base AS client-runtime

COPY --from=builder /app/build/db_health_client /app/db_health_client

ENTRYPOINT ["/app/db_health_client"]
CMD ["users"]