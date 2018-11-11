CC=gcc
CFLAGS=-Wall -Wextra -std=c99

all: readfile

readfile: readfile.c
	$(CC) $(CFLAGS) $^ -o $@



check: readfile
	valgrind ./readfile dollhouse

clean:
	rm -f readfile
