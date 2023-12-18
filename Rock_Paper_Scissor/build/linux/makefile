CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
SRC_DIR = ../../src
INCLUDE_DIR = ../../include
BIN_DIR = ../../bin/linux
TEMP_DIR = ../../temp/linux
TARGET = $(BIN_DIR)/Application.exe

# Add the path to your utilities source files
UTILITIES_SRC_DIR = ../../src/utilities
UTILITIES_INCLUDE_DIR = ../../include/utilities

# Collect all source files for application and utilities
APPLICATION_SRCS = $(wildcard $(SRC_DIR)/*.cpp)
UTILITIES_SRCS = $(wildcard $(UTILITIES_SRC_DIR)/*.cpp)

# Generate object files for all source files
APPLICATION_OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(TEMP_DIR)/%.o, $(APPLICATION_SRCS))
UTILITIES_OBJS = $(patsubst $(UTILITIES_SRC_DIR)/%.cpp, $(TEMP_DIR)/%.o, $(UTILITIES_SRCS))

# Combine all object files
OBJS = $(APPLICATION_OBJS) $(UTILITIES_OBJS)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rules for generating object files for application sources
$(TEMP_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $< -I$(INCLUDE_DIR) -I$(UTILITIES_INCLUDE_DIR)

# Rules for generating object files for u
