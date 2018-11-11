CC=gcc
CFLAGS=-Wall -Wextra -std=c99 -g
VFLAGS=--leak-check=full

prog1: oppgave1
	$(CC) $(CFLAGS) oppgave1.c -o prog1

run: prog1
	./prog1

check: prog1
	valgrind $(VFLAGS) ./prog1

clean:
	rm -f prog1
