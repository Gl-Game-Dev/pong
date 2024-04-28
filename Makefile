all: 
	cc ./src/*.c `pkg-config --libs --cflags raylib` -o Jpong
	./Jpong

debug:
	cc source.c `pkg-config --libs --cflags raylib` -g -o YourGame
	gdb ./YourGame
