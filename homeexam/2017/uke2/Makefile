CC=gcc
CFLAGS=-Wall -Wextra -std=c99

test:person.c
	  # $(CC) $(CFLAGS) hello.c -o hello
		 $(CC) $(CFLAGS) $^ -o $@
#%:%.c generic maker
#	$(CC) $(CFLAGS) $^ -o $@
run: test
	   ./test

clean:
	  rm -f test
