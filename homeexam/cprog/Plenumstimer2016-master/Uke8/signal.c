#define _GNU_SOURCE
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int flag_exit = 0;

/*
 * void (*sa_handler)(int)
 * void (*)(int)
 */
void handler(int signum)
{
	printf("signum: %d\n", signum);
	printf("name: %s\n", strsignal(signum));
	flag_exit = 1;
}

int main(void)
{
	struct sigaction sa;
	memset(&sa, 0, sizeof(struct sigaction));

	sa.sa_handler = handler;
	/* ctrl+c -> SIGINT */
	if (sigaction(SIGINT, &sa, NULL) == -1) {
		perror("sigaction()");
		exit(EXIT_FAILURE);
	}

	int seconds = 5;
	printf("Waiting...\n");
	while (flag_exit == 0) {
		errno = 0;
		seconds = sleep(seconds);
		if (errno == EINTR) {
			printf("Interrupted :(\n");
		}
	}

	return 0;
}
