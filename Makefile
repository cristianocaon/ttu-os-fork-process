LFLAGS=-std=c99
CC=gcc

all: 
	$(CC) $(LFLAGS) -o hello_child hello_child.c
	$(CC) $(LFLAGS) -o hello_child2 hello_child2.c
