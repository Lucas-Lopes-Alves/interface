CXX = g++
CC = gcc

LDFLAGS = -lglfw
CXXFLAGS = -Iinclude
CFLAGS = -Iinclude

SRCS_C = $(shell find src -type f -name "*.c")
SRCS_CPP = $(shell find src -type f -name "*.cpp")

OBJS = $(patsubst src/%.c, build/obj/%.o, $(SRCS_C))
OBJS += $(patsubst src/%.cpp, build/obj/%.o, $(SRCS_CPP))

all: $(OBJS)
	mkdir -p build/bin
	$(CXX) $(OBJS) -o build/bin/interface $(LDFLAGS)

build/obj/%.o: src/%.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
build/obj/%.o: src/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build/*