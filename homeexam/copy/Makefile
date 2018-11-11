CC=gcc
CFLAG=-Wall -Wextra -std=c99

myshell: myshell.c linked_list.c
	$(CC) $(CFLAG) $^ -o $@

debug: CFLAG+=-DDEBUG
debug: myshell

run: myshell
	./myshell

memtest: myshell
	vlgrind ./myshell

memtestExtra: myshell
	valgrind  --leak-check=full ./myshell

clean:
	rm -f myshell linked_list
