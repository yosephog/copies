#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/*
 * fds[0] = read
 * fds[1] = write
 */
#define READ 0
#define WRITE 1

int main(void)
{
	/* fds = file descriptors */
	int fds[2];	

	if (pipe(fds) == -1) {
		perror("pipe()");
		exit(EXIT_FAILURE);
	}

	printf("yay\n");

	/* read / write */

	pid_t pid = fork();
	if (pid == -1) {
		perror("fork()");
		exit(EXIT_FAILURE);
	}

	char *msg = "Les godt foer eksamen!! - HP 2016";

	/*
	 * int -> size of text
	 * char * -> text
	 */
	if (pid == 0) { /* child */
		close(fds[READ]);
		int msg_size = strlen(msg);
		//int msg_size = -1;
		write(fds[WRITE], &msg_size, sizeof(int));
		write(fds[WRITE], msg, strlen(msg));
	} else {		/* parent */
		int size;
		close(fds[WRITE]);
		read(fds[READ], &size, sizeof(int));
		printf("size: %d\n", size);

		/* legal size: 0 - 255 */
		if (size < 0 || size > 255) {
			fprintf(stderr, "Invalid size!\n");
			return 1;
		}

		char *buf = calloc(1, size + 1);

		read(fds[READ], buf, size);
		printf("message: %s\n", buf);

		free(buf);
	}

	return 0;
}
