#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

int running = 1;

/*
 * Server:
 * 1. lage en socket med socket()
 * 2. opprette en sockaddr_in struct
 * 3. bind()
 * 4. listen()
 * 5. accept()
 *
 *
 * Lytte paa IP/port
 *
 */

/*
 * Create socket, bind, and listen
 * @ip		bind to this IP
 * @port	this port
 *
 * Returns socket on success, -1 on error.
 */
int create_socket(char *ip, char *port)
{
	int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sock == -1) {
		perror("socket()");
		return -1;
	}

	int port_num = atoi(port);

	struct sockaddr_in server_addr;
	memset(&server_addr, 0, sizeof(struct sockaddr_in));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(port_num);
#if 1
	int ip_ret = inet_pton(AF_INET, ip, &server_addr.sin_addr.s_addr);
	if (ip_ret != 1) {
		if (ip_ret == 0) {
			fprintf(stderr, "Invalid IP address: %s\n", ip);
		} else {
			perror("inet_pton()");
		}
		close(sock);
		return -1;
	}
#else
	server_addr.sin_addr.s_addr = INADDR_ANY;
#endif

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

	printf("Bound successfully to %s:%d!\n", ip, port_num);

	if (listen(sock, SOMAXCONN)) {
		perror("listen()");
		close(sock);
		return -1;
	}

	return sock;
}

int accept_connections(int sock)
{
	struct sockaddr_in client_addr;
	memset(&client_addr, 0, sizeof(client_addr));
	socklen_t addr_len = sizeof(client_addr);

	int client_sock = accept(sock, (struct sockaddr *)&client_addr, &addr_len);
	if (client_sock == -1) {
		if (errno == EINTR)
			return 0;
		perror("accept()");
		close(sock);
		return -1;
	}

	printf("Client connected! :))\n");

	char *client_ip = inet_ntoa(client_addr.sin_addr);
	uint32_t client_ip_bin = ntohl(client_addr.sin_addr.s_addr);
	printf("IP/port: %s/0x%x\n", client_ip, client_ip_bin);

	char buf[256] = { 0 };
	ssize_t ret = recv(client_sock, buf, sizeof(buf) - 1, 0);
	if (ret == 0) {
		printf("Client disconnected :(\n");
	} else if (ret == -1) {
		if (errno == EINTR)
			return 0;
		perror("recv()");
		close(sock);
		return -1;
	} else {
		printf("Message from client: %s\n", buf);
	}

	ret = send(client_sock, buf, strlen(buf), 0);
	if (ret == -1) {
		if (errno == EINTR)
			return 0;
		perror("send()");
		close(sock);
		return -1;
	}

	close(client_sock);

	return 0;
}

void handler(int signum)
{
	printf("handler\n");
	running = 0;
}

int main(int argc, char *argv[])
{
	int sock;
	
	if (argc != 3) {
		fprintf(stderr, "Usage: %s <IP> <port>\n", argv[0]);
		return 0;
	}

	struct sigaction sa;
	memset(&sa, 0, sizeof(sa));

	sa.sa_handler = handler;

	if (sigaction(SIGINT, &sa, NULL)) {
		perror("sigaction()");
		exit(EXIT_FAILURE);
	}

	sock = create_socket(argv[1], argv[2]);
	if (sock == -1) {
		exit(EXIT_FAILURE);
	}

	while (running) {
		if (accept_connections(sock) == -1) {
			break;
		}
	}

	/* cleanup */
	close(sock);

	return 0;
}
