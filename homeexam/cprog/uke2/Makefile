CC= gcc
CFLAGS= -Wall -Wextra -std=c99 -g
VFLAGS=--leak-check=full

all:	prog1 prog2 prog3

prog1:uke2
	$(CC) $(CFLAGS) uke2.c -o prog1

prog2:02.c
	$(CC) $(CFLAGS) 02.c -o prog2

prog3:022.c
	$(CC) $(CFLAGS) 022.c -o prog3

memtest1:	all
	valgrind $(VFLAGS) ./prog1

memtest2: all
	valgrind $(VFLAGS) ./prog2

memtest3:	all
	valgrind $(VFLAGS) ./prog3

clean:
	rm -f prog1 prog2 prog3

target:	depencencies
	command
