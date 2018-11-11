CC=gcc
CFLAGS=-Wall -Wextra -std=gnu99

.PHONEY: all clean run

all: mmap shm shm_client signal

mmap:	mmap.c
	$(CC) $(CFLAGS) $^ -o $@

shm: shm.c
	$(CC) $(CFLAGS) $^ -o $@

shm_client: shm_client.c
	$(CC) $(CFLAGS) $^ -o $@

signal: signal.c
	$(CC) $(CFLAGS) $^ -o $@


run: mmap
	./mmap hello

clean:
	rm -f mmap, shm shm_client signal
