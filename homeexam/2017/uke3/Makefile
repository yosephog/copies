CC=gcc
CFLAGS=-Wall -Wextra -std=c99

read:read.c
	$(CC) $(CFLAGS) $^ -o $@

run:read
	./read

check:read
	valgrind --leak-check=full ./read

clean:
	rm -f read
