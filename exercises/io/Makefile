# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

# Target executable name
TARGET = main

# Source files (.cc)
SRCS = main.cc cli_args.cc

# Object files (.o)
OBJS = $(SRCS:.cc=.o)

# Default target
all: $(TARGET)

# Link object files into executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

# Compile .cc into .o
%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJS) $(TARGET)

# Optional: rebuild everything
rebuild: clean all