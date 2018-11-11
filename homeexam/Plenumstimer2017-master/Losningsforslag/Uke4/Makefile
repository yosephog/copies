CC=gcc
CFLAGS=-Wall -Wextra -std=c99

.PHONY: all clean

all: fil read_num write_num binary_stuff

fil: fil.c
	$(CC) $(CFLAGS) $^ -o $@

read_num: read_num.c
	$(CC) $(CFLAGS) $^ -o $@

write_num: write_num.c
	$(CC) $(CFLAGS) $^ -o $@

binary_stuff: binary_stuff.c util.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f fil read_num write_num binary_stuff
