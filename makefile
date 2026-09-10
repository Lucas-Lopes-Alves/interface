FLAGS = -Iinclude -lglfw -lGL
CC = g++
SRC = src/interface.cpp src/wrapper.cpp

$(shell mkdir -p bin)

all:
	$(CC) $(SRC) -o bin/interface $(FLAGS)