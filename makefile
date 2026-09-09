FLAGS = -I deps -L deps/glfw/lib-mingw-w64 -lglfw3 -lgdi32 -lopengl32
CC = g++

all:
	$(CC) src/interface.cpp -o bin/interface.exe $(FLAGS)