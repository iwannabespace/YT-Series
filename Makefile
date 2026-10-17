CXX = clang++
CXXFLAGS = -Wall -Wextra -std=c++23
LDLIBS = -lraylib
BINARY = chat

SOURCES = $(wildcard *.cpp src/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

.PHONY: all clean

all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CXX) $^ $(LDLIBS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(BINARY) $(OBJECTS)