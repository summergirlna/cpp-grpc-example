BUILD_DIR := build
TARGET := cpp-grpc-example
SERVER_TARGET := db_health_server
CLIENT_TARGET := db_health_client
TABLE ?= users

.PHONY: configure build run test clean rebuild

configure:
	cmake -S . -B $(BUILD_DIR)

build:
	cmake --build $(BUILD_DIR)

run: configure build
	./$(BUILD_DIR)/$(TARGET) $(TABLE)

server: configure build
	./$(BUILD_DIR)/$(SERVER_TARGET)

client: configure build
	./$(BUILD_DIR)/$(CLIENT_TARGET) $(TABLE)

test: configure build
	ctest --test-dir $(BUILD_DIR) --output-on-failure

format:
	clang-format -i src/*.cpp src/*.h tests/*.cpp

clean:
	rm -rf $(BUILD_DIR)

rebuild: clean build
