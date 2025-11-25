TARGET = cumbot

X86_CXX = g++
ARM_CXX = aarch64-linux-gnu-g++

CXX ?= $(X86_CXX)

SRC := $(wildcard src/*.cpp)

ifeq ($(CXX),$(ARM_CXX))
    BUILD_DIR := build/arm
    CXXFLAGS := -Iinclude --sysroot=./sysroot -I./sysroot/usr/include
    LDFLAGS := --sysroot=./sysroot -L./sysroot/usr/lib/aarch64-linux-gnu -L./sysroot/lib/aarch64-linux-gnu -L./sysroot/usr/lib
    LDLIBS := -ldpp -lssl -lcrypto -lz -lcurl
else
    BUILD_DIR := build/x86
    CXXFLAGS := -Iinclude
    LDFLAGS :=
    LDLIBS := -ldpp -lcurl
endif

OBJS := $(patsubst src/%.cpp,$(BUILD_DIR)/%.o,$(SRC))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

$(BUILD_DIR)/%.o: src/%.cpp | $(BUILD_DIR)
	$(CXX) -std=c++20 $(CXXFLAGS) -c -o $@ $<

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf build/x86 build/arm $(TARGET)

.PHONY: all clean