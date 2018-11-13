CC=gcc
CFLAG=-Wall -Wextra -std=c99
VFLAGS=--leak-check=full

mysh: mysh.c
	$(CC) $(CFLAG) $^ -o $@

debug: CFLAG+=-DDEBUG
debug: mysh

run: mysh
	./mysh

memtest: mysh
	valgrind ./mysh

memtestExtra: mysh
	valgrind  $(VFLAGS) ./mysh

clean:
	rm -f mysh
