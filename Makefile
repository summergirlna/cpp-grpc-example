BUILD_DIR := build
TARGET := cpp-grpc-example

.PHONY: configure build run clean rebuild

configure:
	cmake -S . -B $(BUILD_DIR)

build:
	cmake --build $(BUILD_DIR)

run: configure build
	./$(BUILD_DIR)/$(TARGET)

clean:
	rm -rf $(BUILD_DIR)

rebuild: clean build
