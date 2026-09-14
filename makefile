CXX = g++
CC = gcc

TARGET = build/bin/libinterface.so

LDFLAGS = -shared
LDLIBS = -lglfw

CXXFLAGS = -fPIC -Iinclude
CFLAGS = -fPIC -Iinclude

SRCS_C = $(shell find src -type f -name "*.c")
SRCS_CPP = $(shell find src -type f -name "*.cpp")

OBJS = $(patsubst src/%.c, build/obj/%.o, $(SRCS_C))
OBJS += $(patsubst src/%.cpp, build/obj/%.o, $(SRCS_CPP))

all: $(TARGET)

$(TARGET): $(OBJS)
	mkdir -p $(dir $@)
	$(CXX) $> $(LDFLAGS) -o $@ $(LDLIBS)

build/obj/%.o: src/%.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
build/obj/%.o: src/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build/*