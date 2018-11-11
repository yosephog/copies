CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -std=gnu99 -g
BINARIES=strings sizeof

all: $(BINARIES)

strings: strings.c oblig1_tests.c
	$(CC) $(CFLAGS) $^ -o $@

debug_sizeof: CFLAGS+=-DDEBUG
debug_sizeof: sizeof

%:%.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(BINARIES)

