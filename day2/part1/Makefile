# Compiler
CXX = clang++

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++17 -I..

# Linker flags (if any specific to Clang)
LDFLAGS =

# Source files
SRCS = main.cpp ../helpers.cpp

# Object files
OBJS = $(patsubst %.cpp,%.o,$(notdir $(SRCS)))

# Executable name
PART1 = part1

# Default PARTX
all: $(PART1)

# Linking
$(PART1): $(OBJS)
	$(CXX) $(LDFLAGS) -o $(PART1) $(OBJS)

# Compilation
%.o: ../%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJS) $(PART1)

# Phony targets
.PHONY: all clean