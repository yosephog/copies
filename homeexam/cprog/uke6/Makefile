CC=gcc
CFLAGS=-Wall -Wextra -std=c99
VFLAGS=--leak-check=full --track-origins=yes --show-reachable=yes

env: env.c
	$(CC) $(CFLAGS) $^ -o $@

ikea: ikea.c
		$(CC) $(CFLAGS) $^ -o $@

run: ikea
	 ./ikea data.dat

check: ikea
	valgrind $(VFLAGS) ./ikea data.dat



clean:
	rm -f env ikea
