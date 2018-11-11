CC=gcc
CFLAGS=-Wall -Wextra -std=c99

all: pipe

pipe: pipe.c
	$(CC) $(CFLAGS) $^ -o $@

run: pipe
	./pipe

check: pipe
	valgrind ./pipe

clean:
	rm -f pipe
