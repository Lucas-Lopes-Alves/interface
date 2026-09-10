FLAGS = -Iinclude -lglfw -lGL
CC = g++

$(shell mkdir -p bin)

all:
	$(CC) src/interface.cpp -o bin/interface $(FLAGS)