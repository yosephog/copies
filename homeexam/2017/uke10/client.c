#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
/*
* client
*1. lage en socket mded socket
*2. opprette en sockadder_in struct
*3 koble til socket med connect

*Div info
AF_INET /PF_INET
AF= address family
PF= protocol family

koble til server with IP og Portnumber
bruker TCP
*/

int main(int argc,char* argv[]){
  if(argc != 4){
    fprintf(stderr, "usage: %s<IP> <port> <message>\n",argv[0]);
    return 0;
  }
 char*  ip=argv[1];
  int port=atoi(argv[2]);
  char* msg=argv[3];
  int sock;
  // can use 0 for  IPPROTO_TCP. This uses the best automatically
  sock=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
  if(sock == -1){
    perror("socket()");
    exit(EXIT_FAILURE);
  }

  struct sockaddr_in serverAdder;
  memset(&serverAdder,0,sizeof(struct sockaddr_in));
  serverAdder.sin_family=AF_INET;
  //TODO: error check for inet_pton
  int inet=inet_pton(AF_INET,ip,&serverAdder.sin_addr.s_addr);
   if(inet != 1){
     if(inet == 0){
       fprintf(stderr, "Ivalid ip address %s\n",ip );
       return 0;
     }
     else{
     perror("inet_pton()");

   }
   write(sock,msg,strlen(msg));
   close(sock);
   exit(EXIT_FAILURE);
   }
  //htons host to network short
  serverAdder.sin_port=htons(port);
  /*
  IP-:127.0.0.1
  PORT: 4444
  */
  printf("Connecting to %s %d \n",ip,port );
int con= connect(sock,(struct sockaddr*)&serverAdder,sizeof(serverAdder));
 if(con == -1){
   perror("connect()");
   exit(EXIT_FAILURE);
 }
 printf("yay connected \n");
 ssize_t ret=send(sock,msg,strlen(msg),0);
 if(ret==-1){
   perror("send()");
   exit(EXIT_FAILURE);
 }
 char buf[256]={0};
  ret=recv(sock,buf,sizeof(buf)-1,0);
 if(ret== 0){
   printf("server dissconnected\n");
 }else if(ret == -1){
   perror("write()");
   close(sock);
   exit(EXIT_FAILURE);
 }
 else{
   printf("Recived message from server-: %s\n",buf );
 }
 close(sock);
  return 0;
}
