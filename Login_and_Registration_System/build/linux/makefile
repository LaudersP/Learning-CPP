CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
SRC_DIR = ../../src
INCLUDE_DIR = ../../include
BIN_DIR = ../../bin/linux
TEMP_DIR = ../../temp/linux
TARGET = $(BIN_DIR)/Application.exe

# Add the path to LogginSystem source files
LOGGINSYSTEM_SRC_DIR = ../../src/LogginSystem
LOGGINSYSTEM_INCLUDE_DIR = ../../include/LogginSystem

# Add the path to RegisterSystem source files
REGISTERSYSTEM_SRC_DIR = ../../src/RegisterSystem
REGISTERSYSTEM_INCLUDE_DIR = ../../include/RegisterSystem

# Collect all source files for application and utilities
APPLICATION_SRCS = $(wildcard $(SRC_DIR)/*.cpp)
LOGGINSYSTEM_SRCS = $(wildcard $(LOGGINSYSTEM_SRC_DIR)/*.cpp)
REGISTERSYSTEM_SRCS = $(wildcard $(REGISTERSYSTEM_SRC_DIR)/*.cpp)

# Generate object files for all source files
APPLICATION_OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(TEMP_DIR)/%.o, $(APPLICATION_SRCS))
LOGGINSYSTEM_OBJS = $(patsubst $(LOGGINSYSTEM_SRC_DIR)/%.cpp, $(TEMP_DIR)/%.o, $(LOGGINSYSTEM_SRCS))
REGISTERSYSTEM_OBJS = $(patsubst $(REGISTERSYSTEM_SRC_DIR)/%.cpp, $(TEMP_DIR)/%.o, $(REGISTERSYSTEM_SRCS))

# Combine all object files
OBJS = $(APPLICATION_OBJS) $(LOGGINSYSTEM_OBJS) $(REGISTERSYSTEM_OBJS)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rules for generating object files for application sources
$(TEMP_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $< -I$(INCLUDE_DIR) -I$(LOGGINSYSTEM_INCLUDE_DIR) -I$(REGISTERSYSTEM_INCLUDE_DIR)