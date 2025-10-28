TARGET = cumbot

X86_CXX = g++
ARM_CXX = aarch64-linux-gnu-g++

CXX ?= $(X86_CXX)

SRC := $(wildcard src/*.cpp)

ifeq ($(CXX),$(ARM_CXX))
    BUILD_DIR := build/arm
    CXXFLAGS := -O3
else
    BUILD_DIR := build/x86
    CXXFLAGS :=
endif

OBJS := $(patsubst src/%.cpp,$(BUILD_DIR)/%.o,$(SRC))

LDLIBS := -lboost_system -lpthread -lssl -lcrypto -lpthread

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(LDLIBS)

$(BUILD_DIR)/%.o: src/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf build/*.o build/x86/*.o build/arm/*.o $(TARGET)
