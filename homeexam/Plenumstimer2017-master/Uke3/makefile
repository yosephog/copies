CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -std=c99 -g
BINARIES=oppg2 oppg2b oppg2malloc

all: $(BINARIES)

run_malloc: oppg2malloc
	./oppg2malloc

%:%.c
	$(CC) $(CFLAGS) $^ -o $@

check: oppg2malloc
	valgrind --leak-check=full --track-origins=yes ./oppg2malloc


clean:
	rm -f $(BINARIES)

