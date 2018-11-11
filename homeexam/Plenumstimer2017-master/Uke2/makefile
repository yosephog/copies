CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -std=c11 -g
BINS=person oppg1

person: person.c
	$(CC) $(CFLAGS) person.c -o person

%:%.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(BINS)

