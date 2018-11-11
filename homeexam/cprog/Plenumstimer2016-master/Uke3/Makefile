# makefilen inneholder ikke targets for alt, men det
# er lett å kopiere og endre navn på filer og output
# for å få de targets man vil ha

CC=gcc
CFLAGS=-Wall -Wextra -std=c99 -g

.PHONY: run check clean

01: 01.c
	$(CC) $(CFLAGS) 01.c -o 01

#read.o: read.c
#	$(CC) $(CFLAGS) -c read.c
#
#person.o: person.c
#	$(CC) $(CFLAGS) -c person.c

# $@: target
# $<: første dependecy
# $^: alle dependencies

%.o: %.c person.h Makefile
	$(CC) $(CFLAGS) $< -c

person: read.o person.o
	$(CC) $(CFLAGS) $^ -o $@

array_ting: array_ting.o
	$(CC) $(CFLAGS) $^ -o $@

array_ting_check: CFLAGS += -DDEBUG
array_ting_check: array_ting
	valgrind --leak-check=full ./array_ting hei INF1060

run: person
	#./01
	./person

check: person
	#valgrind --leak-check=full ./01
	valgrind --leak-check=full ./person

clean:
	rm -f 01 *.o a.out person read copy array_ting
