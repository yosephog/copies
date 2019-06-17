#include <stdio.h>
#include <sys/socket.h>
#include "protocol.h"
#include <arpa/inet.h>
#include <string.h>

int read_message(int fd, int* operator, int* a, int* b) {
    char buffer[MESSAGE_SIZE];
    int ret = recv(fd, buffer, MESSAGE_SIZE, 0);
	printf("ret: %d\n", ret);

    if (ret <= 0) return ret;

    if (buffer[0] == '+') {
        *operator = 1;
    } else if (buffer[0] == '-') {
        *operator = 2;
    } else if (buffer[0] == '*') {
        *operator = 3;
    } else if (buffer[0] == '/') {
        *operator = 4;
    }

	//"+ 123 567"
    char* arg = strstr(buffer, " ") + sizeof(char);
    *a = atoi(arg);

    arg = strstr(arg, " ") + sizeof(char);
    *b = atoi(arg);

    return ret;
}

int send_message(int fd, int error, int res) {
    char buffer[REPLY_SIZE] = { 0 };

    if(error) {
        sprintf(buffer, "ERROR: %d\n", error);
    } else {
        sprintf(buffer, "RESULT: %d\n", res);
    }

	size_t sent = 0;
    while (sent != strlen(buffer)) {
		char* to_send_from = buffer+sent;

		int ret = send(fd, to_send_from, strlen(to_send_from), 0);
		if (ret <= 0) {
			perror("send()");
		} else {
			sent += ret;
		}
	}
	return sent;
}
