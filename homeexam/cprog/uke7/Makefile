CC=gcc
CFLAGS=-Wall -Wextra -std=c99

all: open

open: open.c
	$(CC) $(CFLAGS) $^ -o $@

run: open
	./open.c hei.txt

clean:
	rm -f open
