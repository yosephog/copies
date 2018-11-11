CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -std=c11 -g
BINS=person

%:%.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(BINS)

