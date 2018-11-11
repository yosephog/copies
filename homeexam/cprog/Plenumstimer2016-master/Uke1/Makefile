CC=gcc
CFLAGS=-Wall -Wextra -std=c99

test: test.c
	$(CC) $(CFLAGS) $^ -o $@

run: test
	./test

clean:
	rm -f test
