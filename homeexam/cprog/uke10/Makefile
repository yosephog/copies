CC=gcc
CFLAGS=-Wall -Wextra -std=gnu99



all: server client

client:	client.c
	$(CC) $(CFLAGS) $^ -o $@

server: server.c
	$(CC) $(CFLAGS) $^ -o $@

run: server
	./server 127.0.0.1 4444

runc: client
	./client 127.0.0.1 4444 hello
clean:
	rm -f client server
