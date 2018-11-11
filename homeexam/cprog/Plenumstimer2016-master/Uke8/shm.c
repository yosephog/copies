#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/*
 * 1. shmget
 * 2. shmat - shared memory attach
 */
int main(void)
{
	key_t key = 42;

	long page_size = sysconf(_SC_PAGESIZE);
	printf("Page size: %ld\n", page_size);

	/*
	 *  444 = read only
	 *  666 = read/write
	 */
	int id = shmget(key, 512, IPC_CREAT | 0666);
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
	 * send messages, protocol:
	 * M = message
	 * E = end (no more messages)
	 */
	char buf[256];
	for (;;) {
		printf("Message please: ");
		if (fgets(buf, sizeof(buf), stdin) == NULL)
			break;

		strcpy(mem, "M");
		strcat(mem, buf);
		printf("Mem: %s\n", mem);
	}

	strcpy(mem, "E");

	/* Detach */
	shmdt(mem);

	return 0;
}
