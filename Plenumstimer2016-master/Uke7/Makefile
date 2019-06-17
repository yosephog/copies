CC=gcc
CFLAGS=-Wall -Wextra -std=c99

all: open fork_open

open: open.c
	$(CC) $(CFLAGS) $^ -o $@

fork_open: fork_open.c
	$(CC) $(CFLAGS) $^ -o $@

run: open
	./open hei.txt

clean:
	rm -f open
