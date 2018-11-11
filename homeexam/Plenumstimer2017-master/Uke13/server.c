#include <netdb.h> 
#include <stdio.h>
#include <string.h> 
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

#include <netinet/in.h> 
#include <sys/socket.h>

#include "util.h"

#define BUF_SIZE 10202

typedef struct msg_list {
    struct msg_list *next;
    char* msg;
} msg_list_s;

int interrupt_received = 0;
extern int debug_mode;

void alarm_handler(int signal) {
    printf("received signal %d\n", signal);
}

void interrupt_handler(int signal) {
    printf("received signal %d\n", signal);
    interrupt_received = 1;
}

int usage(int argc, char* argv[]) {
    if(argc < 3) {
        printf("USAGE: %s port debug (mode 0/1/2/3 (off, err, warn, info))\n", argv[0]);
        return 1;
    }
    return 0;
}

int get_port(char* port_as_string, unsigned short* port) {
    char* endptr;

    int ret = strtol(port_as_string, &endptr, 10);
    if(endptr == port_as_string && ret == 0) {
        printf("[port]-argument has to be an integer!\n");
        return 1;
    }
    //warn if overflow
    *port = (unsigned short) ret;
    return 0;
}


int main(int argc, char* argv[])
{
    union test dont_use_this;

    dont_use_this.i = 1;
    printf("%d\n", dont_use_this.i);

    dont_use_this.f = 13.14159692;
    printf("%f\n", dont_use_this.f);

    strcpy(dont_use_this.s, "Hei INF1060!");
    printf("%s\n", dont_use_this.s);

    printf("%zu\n", sizeof(dont_use_this));

    char buf[5000] = { 0 };
    char debug_buf[128] = { 0 };

    if(usage(argc, argv)) {
        return EXIT_SUCCESS;
    }

    if(argv[2][0] >= '0' && argv[2][0] <= '3') {
        debug_mode = argv[2][0] - '0';
    }

    sprintf(debug_buf, "debug level: %d", debug_mode);
    debug_print(INFO_LEVEL, debug_buf);

    struct sigaction sa2;
    memset(&sa2, 0, sizeof(struct sigaction));
    sa2.sa_handler = &alarm_handler;

    sigaction(SIGUSR1, &sa2, NULL);

    debug_print(INFO_LEVEL, "Sigaction complete");
    
    struct sigaction sa;
    memset(&sa, 0, sizeof(struct sigaction));
    sa.sa_handler = &interrupt_handler;

    sigaction(SIGINT, &sa, NULL);

    msg_list_s *list_head = (msg_list_s*)calloc(sizeof(msg_list_s), 1);
    msg_list_s *list_tail = list_head;
    msg_list_s *list_walker;

    struct sockaddr_in serveraddr, clientaddr; 
    socklen_t clientaddrlen = sizeof(clientaddr);
    int request_sock, sock, ret;
    unsigned short port;

    ret = get_port(argv[1], &port);
    // same as in client

    request_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    // same as in client
    
    sprintf(debug_buf, "Socket created, number: %d\n", request_sock);
    debug_print(INFO_LEVEL, debug_buf);

    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET; 
    serveraddr.sin_addr.s_addr = INADDR_ANY;
    serveraddr.sin_port = htons(port);

    ret = bind(request_sock, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
    if(ret == -1) {
        perror("bind");
        close(request_sock);
        return EXIT_FAILURE;
    }


    listen(request_sock, SOMAXCONN);
    if(ret == -1) {
        perror("bind");
        close(request_sock);
        return EXIT_FAILURE;
    }

    for(;;) {
        sock = accept(request_sock, (struct sockaddr *)&clientaddr, &clientaddrlen);
        if(ret == -1) {
            perror("accept");
            close(request_sock);
            return EXIT_FAILURE;
        }
        if(interrupt_received) {
            printf("Hei!!\n");
            break;
        }

        size_t r = read(sock, buf, sizeof(buf));
        buf[r] = '\0';
        list_tail->next = (msg_list_s*)calloc(sizeof(msg_list_s), 1);
        list_tail->msg = malloc(r+1);
        strcpy(buf, list_tail->msg); 
        list_tail = list_tail->next;

        for (list_walker = list_head; list_walker; list_walker = list_walker->next) {
            printf("%s\n", list_walker->msg);
        }
    }

    printf("sock: %d\n", sock);

    close(sock);
    close(request_sock);

    return EXIT_SUCCESS;
} 
   
