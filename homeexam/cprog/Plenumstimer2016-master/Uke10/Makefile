CC=gcc
CFLAGS=-Wall -Wextra -std=gnu99 -g

all: client server

client: client.c
	$(CC) $(CFLAGS) $^ -o $@

server: server.c
	$(CC) $(CFLAGS) $^ -o $@

run: server
	./server

clean:
	rm -f server client
