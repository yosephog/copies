CC=gcc
CFLAGS=-Wall -Wextra -std=gnu99 -pedantic -g

all: getaddr

getaddr: getaddr.c
	$(CC) $(CFLAGS) $^ -o $@

pipe: pipe.c
	$(CC) $(CFLAGS) $^ -o $@

# TODO: lage run og check
run: getaddr
	./getaddr www.google.com

check: getaddr
	valgrind --leak-check=full --track-origins=yes ./getaddr ipv6.google.com

runp: pipe
	./pipe

checkp: pipe
	valgrind --leak-check=full --track-origins=yes ./pipe

clean:
	rm -vf getaddr
