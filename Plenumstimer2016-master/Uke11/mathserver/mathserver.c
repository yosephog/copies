#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <sys/select.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include "protocol.h"

#define MAX_CLIENTS 4

int plus(int a, int b, int* error) {
	*error = 0;
	return a + b;
}

int minus(int a, int b, int* error) {
	*error = 0;
	return a - b;
}

int divide(int a, int b, int* error) {
	*error = b == 0;
	if (b == 0) return 0;
	return a / b;
}

int multiply(int a, int b, int* error) {
	*error = 0;
	return a * b;
}

int (*fnptr[5])(int a, int b, int* error) = {
	NULL,
	&plus,
	&minus,
	&multiply,
	&divide,
};

/*
 * Create socket, bind, and listen
 * @ip		bind to this IP
 * @port	this port
 *
 * Returns socket on success, -1 on error.
 */
int create_socket(char *port)
{
	int sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == -1) {
		perror("socket()");
		return -1;
	}

	short port_num = atoi(port);

	struct sockaddr_in server_addr;
	memset(&server_addr, 0, sizeof(struct sockaddr_in));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_port = htons(port_num);

	int yes = 1;
	if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int))) {
		perror("setsockopt()");
		close(sock);
		return -1;
	}

	if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr))) {
		perror("bind()");
		close(sock);
		return -1;
	}

	printf("Bound successfully to port %d!\n", port_num);

	if (listen(sock, SOMAXCONN)) {
		perror("listen()");
		close(sock);
		return -1;
	}

	return sock;
}

int main(int argc, char *argv[])
{
	int sock;
	int connected_clients = 0;
	fd_set read_fds, all_fds;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <port>\n", argv[0]);
		return 0;
	}

	sock = create_socket(argv[1]);
	if (sock == -1) {
		exit(EXIT_FAILURE);
	}

	/* 1. fungerer med en klient
	 * 2. fungere med multiclient
	 *
	 * Protokoll:
	 *	1: operator
	 *	space
	 *	tall1
	 *	space
	 *	tall2
	 */

	FD_ZERO(&all_fds);
	FD_SET(sock, &all_fds);

	printf("MAX SELECT: %d\n", FD_SETSIZE);
	for (;;) {
		read_fds = all_fds;
		int events = select(FD_SETSIZE,
				&read_fds,
				NULL,
				NULL,
				0);

		if (events == -1) {
			perror("select()");
		} else {
			for (int i = 0; i < FD_SETSIZE; i++) {
				if (FD_ISSET(i, &read_fds)) { //readable socket?
					if (i == sock) {
						int client_sock = accept(sock, NULL, NULL);
						if (connected_clients >= MAX_CLIENTS) {
							printf("Refusing connection!\n");
							close(client_sock);
						} else {
							printf("Client connected\n");
							FD_SET(client_sock, &all_fds);
							connected_clients++;
						}
					} else { //client message
						int error, operator, a, b;
						int ret = read_message(i, &operator, &a, &b);
						if (ret < 0) {
							perror("read_message()");
							close(i);
							connected_clients--;
							FD_CLR(i, &all_fds);
							exit(EXIT_FAILURE);
						} else if (ret == 0) {
							perror("dumme folk");
						} else {
							int res = fnptr[operator](a, b, &error);

							send_message(i, error, res);
						}
					}
				}
			}
		}
	}
	//TODO: close server on ctrl-c

	close(sock);

	return 0;
}
