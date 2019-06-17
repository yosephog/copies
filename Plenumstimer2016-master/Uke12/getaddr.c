#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
		return 0;
	}

	const char *hostname = argv[1];
	printf("hostname: %s\n", hostname);

	struct addrinfo hints;
	struct addrinfo *result;
	memset(&hints, 0, sizeof(hints));

	hints.ai_socktype = SOCK_STREAM; /* TCP */
	/* for HE: bruk AF_INET */
	hints.ai_family = AF_UNSPEC; /* IPv4 and IPv6 */

	int ret = getaddrinfo(hostname, NULL, &hints, &result);
	if (ret) {
		fprintf(stderr, "getaddrinfo failed: %s\n", gai_strerror(ret));
		exit(EXIT_FAILURE);
	}

	printf("Success!\n");

	struct addrinfo *rp;
	/* 192.158.123.123 */
	char ip_buf[INET6_ADDRSTRLEN];
	for (rp = result; rp != NULL; rp = rp->ai_next) {
		if (rp->ai_family == AF_INET) {
			struct sockaddr_in *addr = (struct sockaddr_in *)rp->ai_addr;
			inet_ntop(AF_INET, &addr->sin_addr, ip_buf, sizeof(ip_buf));
		} else if (rp->ai_family == AF_INET6) {
			struct sockaddr_in6 *addr = (struct sockaddr_in6 *)rp->ai_addr;
			inet_ntop(AF_INET6, &addr->sin6_addr, ip_buf, sizeof(ip_buf));
		} else {
			/* TODO: error handling */
			fprintf(stderr, "whaat\n");
			continue;
		}

		printf("IP address: %s\n", ip_buf);
	}

	freeaddrinfo(result);

	return 0;
}
