CC=gcc
CFLAGS=-Wall -Wextra -std=c99

all: client server

client: client.c
	$(CC) $(CFLAGS) $^ -o $@

server: server.c
	$(CC) $(CFLAGS) $^ -o $@

runClient:client
	./client

runServer:server
	./server

clean:
	rm -f client,server
