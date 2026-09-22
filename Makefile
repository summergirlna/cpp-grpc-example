BUILD_DIR := build
TARGET := cpp-grpc-example
SERVER_TARGET := db_health_server
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

test: configure build
	ctest --test-dir $(BUILD_DIR) --output-on-failure

clean:
	rm -rf $(BUILD_DIR)

rebuild: clean build
