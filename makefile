# Compiler settings
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Source files
SRCS = Account.cpp Accounts.cpp AccountSystem.cpp main.cpp

# Executable name
TARGET = bank_system

# Default target
all: $(TARGET)

# Link the executable
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

# Clean up compiled files
clean:
	rm -f $(TARGET) *.o

# Phony targets (not actual files)
.PHONY: all clean
