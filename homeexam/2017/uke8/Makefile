CC=gcc
CFLAGS=-Wall -Wextra -std=gnu99
.PHONY: all clean run

all: mmap.c

mmap: mmap.c
	$(CC) $(CFLAGS) $^ -o $@

run: mmap
	./mmap

clean:
	rm -f mmap
