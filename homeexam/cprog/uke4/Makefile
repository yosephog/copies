CC=gcc
CFLAGS=-Wall -Wextra -std=c99
VFLAGS=--leak-check=full

fil: fil.c
	$(CC) $(CFLAGS) $^ -o $@

readnumber: readnumber.c
	$(CC) $(CFLAGS) $^ -o $@

writenumber: writenumber.c
	$(CC) $(CFLAGS) $^ -o $@


memtestfil: fil
	valgrind $(VFLAGS) ./fil

memtestreadnumber: readnumber
	valgrind $(VFLAGS) ./readnumber

memtestwritenumber: writenumber
	valgrind $(VFLAGS) ./writenumber

clean:
	rm -f fil readnumber writenumber
