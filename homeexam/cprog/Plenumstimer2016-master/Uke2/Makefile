CC=gcc
CFLAGS=-Wall -Wextra -std=c99 -g
VFLAGS=--leak-check=full 

all: prog1 prog2 prog3

prog1: 01.c
	$(CC) $(CFLAGS) 01.c -o prog1

prog2: 02.c
	$(CC) $(CFLAGS) 02.c -o prog2

prog3: 03.c
	$(CC) $(CFLAGS) 03.c -o prog3

memtest1: all
	valgrind $(VFLAGS) ./prog1 "hei du der"
	valgrind $(VFLAGS) ./prog1 1234

memtest2: all
	valgrind $(VFLAGS) ./prog2

memtest3: all
	valgrind $(VFLAGS) ./prog3

clean:
	rm -f prog1 prog2 prog3

target: dependencies
	command
