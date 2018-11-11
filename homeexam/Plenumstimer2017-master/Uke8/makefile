CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -std=gnu99 -g

pipe: pipe.c
	$(CC) $(CFLAGS) $^ -o $@

flagg: flagg.o util.o
	$(CC) $(CFLAGS) $^ -o $@

%.o:%.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f *.o flagg pipe
