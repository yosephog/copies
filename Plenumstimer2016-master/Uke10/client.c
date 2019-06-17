#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>

/*
 * Client:
 * 1. lage en socket med socket()
 * 2. opprette en sockaddr_in struct
 * 3. koble til socket med connect()
 *
 *
 * Div info:
 * AF_INET / PF_INET
 * AF = address family
 * PF = protocol family
 *
 *
 * koble til server paa ip og port.
 * TCP
 */
int main(int argc, char *argv[])
{
	int sock;
	
	if (argc != 4) {
		fprintf(stderr, "Usage: %s <IP> <port> <message>\n", argv[0]);
		return 0;
	}

	char *ip = argv[1];
	char *port = argv[2];
	char *msg = argv[3];

	sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sock == -1) {
		perror("socket()");
		exit(EXIT_FAILURE);
	}

	int port_num = atoi(port);

	struct sockaddr_in server_addr;
	memset(&server_addr, 0, sizeof(struct sockaddr_in));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(port_num);
	int ip_ret = inet_pton(AF_INET, ip, &server_addr.sin_addr.s_addr);
	if (ip_ret != 1) {
		if (ip_ret == 0) {
			fprintf(stderr, "Invalid IP address: %s\n", ip);
		} else {
			perror("inet_pton()");
		}
		close(sock);
		exit(EXIT_FAILURE);
	}

	printf("Connecting to %s:%d\n", ip, port_num);
	if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr))) {
		perror("connect()");
		close(sock);
		exit(EXIT_FAILURE);
	}

	printf("yay! connected\n");

	ssize_t ret = send(sock, msg, strlen(msg), 0);
	if (ret == -1) {
		perror("send()");
		close(sock);
		exit(EXIT_FAILURE);
	}

	char buf[256] = { 0 };
	ret = recv(sock, buf, sizeof(buf) - 1, 0);
	if (ret == 0) {
		printf("Server disconnected :(\n");
	} else if (ret == -1) {
		perror("recv()");
		close(sock);
		exit(EXIT_FAILURE);
	} else {
		printf("Message from server: %s\n", buf);
	}

	close(sock);

	return 0;
}
