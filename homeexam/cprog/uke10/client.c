#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>


int main(int argc,char* argv[]){
  /**
   socket(domain,type,protocot)
   domain -: AF_INET address family
             PF_INET protocl family

  **/
  if(argc !=4){
    fprintf(stderr, "usage <ip> <port> <message> %s\n",argv[0] );
    return 0;
  }
  char* address=argv[1];
  int port=atoi(argv[2]);
  char* msg=argv[3];
  int sock;
  sock=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);

 if(sock==-1){
   perror("socket()");
   close(sock);
    exit(EXIT_FAILURE);
 }
 struct sockaddr_in server_addr;
 memset(&server_addr,0,sizeof(struct sockaddr_in));
 server_addr.sin_family=AF_INET;
 int ip_ret=inet_pton(AF_INET,address,&server_addr.sin_addr.s_addr);
 if(ip_ret != 1){
   if(ip_ret == 0)
     fprintf(stderr, "Not a valid address %d\n",ip_ret );
  else{
     perror("inet_pton()");
  }
   close(sock);
   exit(EXIT_FAILURE);
 }
 server_addr.sin_port=htons(port);
 /**
  ip: 127.0.0.1
  port: 4444
 **/
 int connected=connect(sock,(struct sockaddr*)&server_addr,sizeof(server_addr));
  if(connected == -1){
     perror("connect()");
     close(sock);
     exit(EXIT_FAILURE);
  }
 printf("Yay connected...\n");
 printf("Sending message to server %s\n",msg);
 ssize_t client_send=send(sock,msg,sizeof(msg),0);
 if(client_send==-1){
   perror("send()");
  close(sock);
  exit(EXIT_FAILURE);
 }
 char buf[256];
 ssize_t client_recv=recv(sock,buf,sizeof(buf)-1,0);
 if(client_recv == 0){
   printf("Client disconnected \n");
 }
 else  if(client_recv == -1){
    perror("recv()");
    close(sock);

    exit(EXIT_FAILURE);
  }
  else{
      printf("Message from server %s\n",buf );
  }

 close(sock);
  return 0;
}
