#include <netdb.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <netinet/in.h> 
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netdb.h>

#define MSG "Hei det er fint vaer i dag da"

int usage(int argc, char* argv[]) {
    if(argc < 3) {
        printf("USAGE: %s [server-addr] [port]\n", argv[0]);
        return 1;
    }
    return 0;
}

int get_port(char* port_as_string, unsigned short* port) {
    char* endptr;

    int ret = strtol(port_as_string, &endptr, 10);
    if(endptr == port_as_string && ret == 0) {
        return 1;
    }
    *port = (unsigned short) ret;
    return 0;
}

int main(int argc, char* argv[]) {
    if(usage(argc, argv)) {
        return EXIT_SUCCESS;
    }

    int sock, ret;
    unsigned short port;
    struct addrinfo hints;
    struct addrinfo *result, *rp;

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = 0;
    hints.ai_protocol = IPPROTO_TCP;

    ret = getaddrinfo(argv[1], argv[2], &hints, &result);
    if(ret) {
        const char* s = gai_strerror(ret);
        printf("getaddrinfo: %s\n", s);
        return EXIT_FAILURE;
    }

    sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(sock == -1) {
        perror("socket init");
        return EXIT_FAILURE;
    }

    ret = get_port(argv[2], &port);
    if(ret) {
        printf("[port]-argument has to be an integer!\n");
        close(sock);
        return EXIT_FAILURE;
    }

    for (rp = result; rp != NULL; rp = rp->ai_next) {
        ret = connect(sock, rp->ai_addr, rp->ai_addrlen);
        if(!ret) {
            break;
        }
    }

    if(rp == NULL) {
        fprintf(stderr, "No address succeeded!\n");
        close(sock);
        freeaddrinfo(result);
        return EXIT_FAILURE;
    }

    freeaddrinfo(result);

    write(sock, MSG, sizeof(MSG));

    close(sock);
    return EXIT_SUCCESS;
}
