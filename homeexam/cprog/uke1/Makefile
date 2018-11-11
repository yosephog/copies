CC=gcc
CFLAGS=-Wall -Wextra -std=c99

test:hello.c
	  # $(CC) $(CFLAGS) hello.c -o hello
		 $(CC) $(CFLAGS) $^ -o $@

run: test
	   ./test

clean:
	  rm -f test
