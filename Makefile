BUILD_DIR := build
TARGET := cpp-grpc-example
TEST_TARGET := health_checker_test

.PHONY: configure build run test clean rebuild

configure:
	cmake -S . -B $(BUILD_DIR)

build:
	cmake --build $(BUILD_DIR)

run: configure build
	./$(BUILD_DIR)/$(TARGET)

test: configure build
	./$(BUILD_DIR)/$(TEST_TARGET)

clean:
	rm -rf $(BUILD_DIR)

rebuild: clean build
