CC=gcc
CFLAGS=-Wall -Wextra -std=gnu99

.PHONY: all clean run

all: mmap shm shm_client

mmap: mmap.c
	$(CC) $(CFLAGS) $^ -o $@

shm: shm.c
	$(CC) $(CFLAGS) $^ -o $@

shm_client: shm_client.c
	$(CC) $(CFLAGS) $^ -o $@

run: mmap
	./mmap "INF1060 :)))"

clean:
	rm -f mmap shm shm_client
