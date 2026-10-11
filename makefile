CXX ?= g++
CC ?= gcc

MODE ?= debug

TARGET = build/bin/libinterface.so

LDFLAGS = -shared
LDLIBS = -lglfw

CXXFLAGS = -std=c++20 -fPIC -Iinclude
CFLAGS = -fPIC -Iinclude

ifeq ($(MODE),debug)
	CXXFLAGS += -g -O0
else ifeq ($(MODE),release)
	CXXFLAGS += -O2
	CFLAGS += -O2
else ifeq ($(MODE),relwithdebuginfo)
	CXXFLAGS += -O2 -g
endif

SRCS_C = $(shell find src -type f -name "*.c")
SRCS_CPP = $(shell find src -type f -name "*.cpp")

OBJS = $(patsubst src/%.c, build/obj/%.o, $(SRCS_C))
OBJS += $(patsubst src/%.cpp, build/obj/%.o, $(SRCS_CPP))

PYTHON := python3

SHADER_HEADER := build/bin/generated/shaders.hpp
SHADER_SOURCES := shaders/shader.vert shaders/shader.frag
SHADER_SCRIPT := scripts/embed_shaders.py

all: $(TARGET)
	
$(TARGET): $(OBJS)
	mkdir -p $(dir $@)
	$(CXX) $^ $(LDFLAGS) -o $@ $(LDLIBS)

build/obj/renderer.o: src/renderer.cpp $(SHADER_HEADER)
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
build/obj/%.o: src/%.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
build/obj/%.o: src/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(SHADER_HEADER): $(SHADER_SOURCES) $(SHADER_SCRIPT)
	mkdir -p $(dir $@)
	$(PYTHON) $(SHADER_SCRIPT) $(SHADER_SOURCES) $@
	
clean:
	rm -rf build/*