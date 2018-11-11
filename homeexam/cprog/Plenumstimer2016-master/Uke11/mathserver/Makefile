CC=gcc
CFLAGS=-Wall -Wextra -std=gnu99 -g

all: mathserver feil

mathserver: mathserver.c protocol.c
	$(CC) $(CFLAGS) $^ -o $@

feil: feil.c
	$(CC) $(CFLAGS) $^ -o $@

run: server
	./server

clean:
	rm -f server feil
