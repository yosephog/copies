CC=gcc
CFLAGS=-Wall -Wextra -std=c99
VFLAGS=--leak-check=full

fil: fil.c
	$(CC) $(CFLAGS) $^ -o $@

test:test.c
	$(CC) $(CFLAGS) $^ -o $@

sprintf:sprintf.c
	$(CC) $(CFLAGS) $^ -o $@

check: fil
	valgrind $(VFLAGS)  ./fil 5router.dat


check2: test
	valgrind $(VFLAGS) ./test

clean:
	rm -f fil test sprintf
