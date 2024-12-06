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
PART2 = part2

# Default PARTX
all: $(PART2)

# Linking
$(PART2): $(OBJS)
	$(CXX) $(LDFLAGS) -o $(PART2) $(OBJS)

# Compilation
%.o: ../%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJS) $(PART2)

# Phony targets
.PHONY: all clean