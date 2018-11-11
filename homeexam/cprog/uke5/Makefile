CC=gcc
CFLAGS=-Wall -Wextra -std=c99
VFLAGS=--leak-check=full

all: calc

calc: calc.c
	$(CC) $(CFLAGS) $^ -o $@

check: calc
	valgrind $(VFLAGS)  ./calc


clean:
	rm -f calc
