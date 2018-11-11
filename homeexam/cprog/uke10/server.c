#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <signal.h>
/*
* creat sock ,bind and listen
* char* ip  ip address
* char* port_number port
*@ returns -1 on error or return sock on success
*/
 int creat_sock(char* ip,char* port_number){
    int sock;
    int port=atoi(port_number);
    sock=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);

    if(sock==-1){
     perror("socket()");
     close(sock);
      return -1;
   }
   struct sockaddr_in server_addr;
   memset(&server_addr,0,sizeof(struct sockaddr_in));
   server_addr.sin_family=AF_INET;
#if 1
   int ip_ret=inet_pton(AF_INET,ip,&server_addr.sin_addr.s_addr);
   if(ip_ret != 1){
     if(ip_ret == 0)
       fprintf(stderr, "Not a valid address %d\n",ip_ret );
    else{
       perror("inet_pton()");
    }

     close(sock);
     return -1;
   }
   server_addr.sin_port=htons(port);
#else
     server_addr.sin_addr.s_addr=INADDR_ANY;
#endif
     int yes=1;
   if(setsockopt(sock,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof(int))){
     perror("setsockopt()");
     return -1;
   }
    if(bind(sock,(struct sockaddr*)&server_addr,sizeof(server_addr))){
       perror("bind()");
       close(sock);
       return -1;
    }
    printf("binded successfully to ip-add and port  %s %d\n",ip,port );

    if(listen(sock,SOMAXCONN)){
      perror("listen()");
      close(sock);
      return -1;
    }
     return sock;
}
int accept_connaction(int sock){
  struct sockaddr_in client_addr;
  memset(&client_addr,0,sizeof(client_addr));
  socklen_t addr_len=sizeof(client_addr);

  int client_sock=accept(sock,(struct sockaddr*)&client_addr,&addr_len);
  if(client_sock==-1){
    perror("accept()");
    close(sock);
    return -1;
  }
  printf("Client connected\n");
  char buf[256]={0};
  ssize_t client_recv=recv(client_sock,buf,sizeof(buf)-1,0);
  if(client_recv == 0){
    printf("Client disconnected \n");
  }
  else  if(client_recv == -1){
     perror("recv()");
     close(sock);
     close(client_sock);
     return -1;
   }
   else{
       printf("Message from client %s\n",buf );
   }

    printf("sending message to client --> %s \n",buf);
    ssize_t server_send=send(client_sock,buf,sizeof(buf)-1,0);
    if(server_send==-1){
      perror("send()");
     close(sock);
     return -1;
    }
  return 0;
}
void handler(int signum)
{
	printf("handler\n");
	 signum = 0;
}

int main(int argc,char* argv[]){
  if(argc !=3){
    fprintf(stderr, "need ip and port %s\n",argv[0] );
    return 0;
  }
  struct sigaction sa;
	memset(&sa, 0, sizeof(sa));

	sa.sa_handler = handler;

	if (sigaction(SIGINT, &sa, NULL)) {
		perror("sigaction()");
		exit(EXIT_FAILURE);
	}
  int sock;
  sock=creat_sock(argv[1],argv[2]);

 if(sock==-1){
   perror("socket()");
   close(sock);
    exit(EXIT_FAILURE);
 }

 while (handler) {
   if (accept_connaction(sock) == -1) {
     break;
   }
 }

  close(sock);

  return 0;
}
