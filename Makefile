BUILD_DIR := build
TARGET := cpp-grpc-example
TABLE ?= users

.PHONY: configure build run test clean rebuild

configure:
	cmake -S . -B $(BUILD_DIR)

build:
	cmake --build $(BUILD_DIR)

run: configure build
	./$(BUILD_DIR)/$(TARGET) $(TABLE)

test: configure build
	ctest --test-dir $(BUILD_DIR) --output-on-failure

clean:
	rm -rf $(BUILD_DIR)

rebuild: clean build
