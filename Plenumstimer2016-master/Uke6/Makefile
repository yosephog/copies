CC=gcc
CFLAGS=-Wall -Wextra -std=c99 -g # -std=gnu99

all: ikea

env: env.c
	$(CC) $(CFLAGS) $^ -o $@

ikea: ikea.c
	$(CC) $(CFLAGS) $^ -o $@

# run with ./id data2.bin
id: id.c
	$(CC) $(CFLAGS) $^ -o $@

run: ikea
	./ikea data.dat

check: ikea
	valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./ikea data.dat

clean:
	rm -f env ikea
