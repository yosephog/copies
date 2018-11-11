CC=gcc
CFLAGS=-Wall -Wextra -std=c99

all:  pipe

ting: ting.c
	$(CC) $(CFLAGS) $^ -o $@

pipe: pipe.c
	$(CC) $(CFLAGS) $^ -o $@

check: pipe
	valgrind ./pipe

clean:
	rm -f ting
