CC=gcc
CFLAGS=-Wall -Wextra -std=c99 -g
VFLAGS=--leak-check=full 
.PHONY:	run check clean



prog1: 03.c
	$(CC) $(CFLAGS) 03.c -o prog1

#read.o:	read.c
#	$(CC) $(CFLAGS) -c read.c

#person.o:	person.c
	#$(CC) $(CFLAGS) -c person.c
# $^ just pus all that is up on it's place like read.o person.o
person:	read.o person.o
	$(CC) $(CFLAGS) $^ -o person

# copile all files with this notation

# $< puts the first if read.o and person.o puts the read.o in its place

%.o:	%.c
	$(CC) $(CFLAGS) $< -c
# $@ refers to doublearray or the target(proger name)
# $< first dependency
# $^ all dependencies
doublearray:	doublearray.o
	$(CC) $(CFLAGS) $^ -o $@



memtest1: prog1
	valgrind $(VFLAGS) ./prog1

memtest2: read
	valgrind $(VFLAGS) ./read

memtest3:	person
	valgrind $(VFLAGS) ./person

memtest4:	doublearray
	valgrind $(VFLAGS) ./doublearray hello you its me


clear:
	rm -f prog1 read person doublearray
