#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*
 * 1. shmget
 * 2. shmat - shared memory attach
 *
 * I terminalen:
 *
 * ipcs -m
 */
int main(void)
{
	key_t key = 42;
	//key_t key = 0xfa030362;

	long page_size = sysconf(_SC_PAGESIZE);
	printf("Page size: %ld\n", page_size);

	/*
	 *  444 = read only
	 *  666 = read/write
	 */
	int id = shmget(key, 512, 0666);
	if (id == -1) {
		perror("shmget()");
		exit(EXIT_FAILURE);
	}

	char *mem = shmat(id, NULL, 0);
	if (mem == (void *)-1) {
		perror("shmat()");
		exit(EXIT_FAILURE);
	}

	printf("Success: %p\n", mem);

	/*
	 * read messages
	 * M = message
	 * E = end (no more messages)
	 */
	char buf[256] = { 0 };
	for (;;) {
		char type = *mem;
		if (type == 'M') {
			if (strcmp(buf, mem)) {
				strncpy(buf, mem, sizeof(buf) - 1);
				printf("Message: %s\n", buf + 1);
			}
		} else if (type == 'E') {
			break;
		} else {
			fprintf(stderr, "Unknown type: %c (0x%02x)\n", type, type);
		}

		sleep(1);
	}

	/* Detach */
	shmdt(mem);

	return 0;
}
