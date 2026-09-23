BUILD_DIR := build
TARGET := cpp-grpc-example
SERVER_TARGET := db_health_server
CLIENT_TARGET := db_health_client
TABLE ?= users
CLANG_TIDY ?= /opt/homebrew/opt/llvm/bin/clang-tidy
SDKROOT ?= $(shell xcrun --show-sdk-path)
SOURCE_FILES := $(shell find src tests -type f \( -name "*.cpp" -o -name "*.h" \))

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
	clang-format -i $(SOURCE_FILES)

lint: configure
	SDKROOT=$(SDKROOT) $(CLANG_TIDY) $(SOURCE_FILES) -p $(BUILD_DIR) --extra-arg=-isysroot --extra-arg=$(SDKROOT)

clean:
	rm -rf $(BUILD_DIR)

rebuild: clean build
