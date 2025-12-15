# Compiler & flags
CXX := g++
CXXFLAGS := -g -I./include -I/usr/include/SDL2 -D_REENTRANT -std=c++17
LDFLAGS := -lSDL2 -lSDL2_image -lfmt

# Source & build directories
SRC_DIR := src
BUILD_DIR := build

# Find all cpp files in src recursively
SOURCES := $(shell find $(SRC_DIR) -name '*.cpp')
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SOURCES))

# Output executable
TARGET := $(BUILD_DIR)/main

# Default rule
all: $(TARGET) assets

# Link executable
$(TARGET): $(OBJECTS)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)


# Compile cpp -> o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

ASSETS_SRC := assets
ASSETS_DST := $(BUILD_DIR)/assets

assets:
	@mkdir -p $(ASSETS_DST)
	cp -r $(ASSETS_SRC)/* $(ASSETS_DST)/

clean:
	rm -rf $(BUILD_DIR)/*

.PHONY: all clean assets

