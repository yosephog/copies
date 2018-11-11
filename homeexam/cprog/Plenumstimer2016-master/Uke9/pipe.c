#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	/* fds = file descriptors */
	int fds[2];	

	/*
	 * fds[0] = read
	 * fds[1] = write
	 */
	if (pipe(fds) == -1) {
		perror("pipe()");
		exit(EXIT_FAILURE);
	}

	printf("yay\n");

	/* read / write */
	//char *msg = "Les godt foer eksamen!! - HP 2016";
	char *msg = "ls";

	pid_t pid = fork();
	if (pid == -1) {
		perror("fork()");
		exit(EXIT_FAILURE);
	}

	/* parent skriver til child */
	if (pid == 0) { /* child */
		close(fds[0]);

		write(fds[1], msg, strlen(msg));
	} else {		/* parent */
		close(fds[1]);
		dup2(fds[0], STDIN_FILENO);
		char *args[] = { "bash", NULL };
		execve("/bin/bash", args, NULL);
	}

	return 0;
}
