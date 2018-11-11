CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -std=gnu11 -g

person: person.o main.o person.h
	$(CC) $(CFLAGS) $^ -o $@

%.o:%.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f person

