main: main.o framebuffer.o
	gcc -o main main.o framebuffer.o
main.o: main.c framebuffer.h
	gcc -c main.c
