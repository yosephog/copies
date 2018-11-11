CC=gcc
CFLAGS=-Wall -Wextra -std=c99
VFLAGS=--leak-check=full

all: fil

fil:	fil.c
	$(CC) $(CFLAGS) $^ -o $@

check: fil
	valgrind $(VFLAGS) ./fil 1.job

clean:
	rm -f fil
