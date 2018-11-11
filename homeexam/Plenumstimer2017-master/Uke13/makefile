CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -std=gnu11 -g

all: server client

debug_c: CFLAGS+=-DDEBUG
debug_c: client

debug_s: CFLAGS+=-DDEBUG
debug_s: server

server: server.o util.o
	$(CC) $(CFLAGS) $^ -o $@

client: client.o
	$(CC) $(CFLAGS) $^ -o $@

%.o:%.c
	$(CC) $(CFLAGS) -c $^

run_server_err: server
	./server 1234 1

run_server_warn: server
	./server 1234 2

run_server_info: server
	./server 1234 3

run_server: server
	./server 1234 0

clean:
	rm -f *.o client server
