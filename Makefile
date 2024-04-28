all: 
	cc ./src/*.c `pkg-config --libs --cflags raylib` -o Jpong
	./Jpong

windows: 
	x86_64-w64-mingw32-gcc -o jpong.exe src/*.c -Llib -lraylib -Iinclude -lgdi32 -lwinmm
