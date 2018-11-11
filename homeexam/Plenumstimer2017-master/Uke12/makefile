CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -std=gnu11 -g

all: server client

debug_c: CFLAGS+=-DDEBUG
debug_c: all

debug_s: CFLAGS+=-DDEBUG
debug_s: all

server: server.o
	$(CC) $(CFLAGS) $^ -o $@

client: client.o
	$(CC) $(CFLAGS) $^ -o $@

%.o:%.c
	$(CC) $(CFLAGS) -c $^

run_server:
	./server

clean:
	rm -f *.o client server
