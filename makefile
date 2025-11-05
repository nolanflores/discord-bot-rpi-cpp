TARGET = cumbot

X86_CXX = g++
ARM_CXX = aarch64-linux-gnu-g++

CXX ?= $(X86_CXX)

SRC := $(wildcard src/*.cpp)

ifeq ($(CXX),$(ARM_CXX))
    BUILD_DIR := build/arm
    CXXFLAGS := -O3 -Iinclude
else
    BUILD_DIR := build/x86
    CXXFLAGS := -Iinclude
endif

OBJS := $(patsubst src/%.cpp,$(BUILD_DIR)/%.o,$(SRC))

LDLIBS := -ldpp

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(LDLIBS)

$(BUILD_DIR)/%.o: src/%.cpp | $(BUILD_DIR)
	$(CXX) -std=c++20 $(CXXFLAGS) -c -o $@ $<

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf build/*.o build/x86/*.o build/arm/*.o $(TARGET)
