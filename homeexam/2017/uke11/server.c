#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
/*
* server
*1. lage en socket mded socket
*2. opprette en sockadder_in struct
*3 bind
4 listen
5 accept

*lytte paa ip

*Div info
AF_INET /PF_INET
AF= address family
PF= protocol family

koble til server with IP og Portnumber
bruker TCP
*/

int creatSocket(char* ip,int  port){
  int sock;
  sock=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
  if(sock == -1){
    perror("socket()");
    return -1;
  }

  struct sockaddr_in serverAdder;
  memset(&serverAdder,0,sizeof(struct sockaddr_in));
  serverAdder.sin_family=AF_INET;
  serverAdder.sin_port=htons(port);
#if 0
  int inet=inet_pton(AF_INET,ip,&serverAdder.sin_addr.s_addr);
   if(inet != 1){
     if(inet == 0){
       fprintf(stderr, "Ivalid ip address %s\n",ip );
       return -1;
     }
     else{
     perror("inet_pton()");

   }
   close(sock);
   return -1;
  // exit(EXIT_FAILURE);
 }
 #else
    serverAdder.sin_addr.s_addr=INADDR_ANY;
 #endif
 int yes=1;
 if(setsockopt(sock,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof(yes))){
   perror("setsocktopt()");
   return  -1;
 }
  int binder= bind(sock,(struct sockaddr *)&serverAdder,sizeof(serverAdder));
   if(binder == -1){
     perror("bind()");
     return -1;
     //exit(EXIT_FAILURE);
   }
   printf("bound sucessfully\n");
   // backlog how many you can accept
    if(listen(sock,SOMAXCONN)){
      perror("listen()");
      close(sock);
      return -1;
      //exit(EXIT_FAILURE);
    }
    return sock;
}
int acceptConnection(int sock){
  struct sockaddr_in client_addr;
  memset(&client_addr,0,sizeof(struct sockaddr_in));
  socklen_t addr_len=sizeof(client_addr);
  int client_sock=accept(sock,(struct sockaddr*)&client_addr,&addr_len);
  if(client_sock == -1){
    perror("accept()");
    close(sock);
    return -1;
  }

 printf("client connected \n" );
 char* client_ip=inet_ntoa(client_addr.sin_addr);
 // change the order of the address
 uint32_t client_ip_bin=ntohl(client_addr.sin_addr.s_addr);
 printf("IP/port %s/0x%x \n",client_ip,client_ip_bin);
 char buf[256]={0};
 ssize_t ret=recv(client_sock,buf,sizeof(buf)-1,0);
 if(ret== 0){
   printf("client dissconnected\n");
 }else if(ret == -1){
   perror("recv()");
   close(sock);
   return -1;
 }
 else{
   printf("Recived message from client-: %s\n",buf );
 }
  ret=send(client_sock,buf,sizeof(buf),0);
 if(ret==-1){
   perror("send()");
   return -1;
 }
 close(client_sock);
 return 0;
}
int main(int argc,char* argv[]){
  if(argc != 3){
    fprintf(stderr, "usage: %s<IP> <port>\n",argv[0]);
    return 0;
  }
 char*  ip=argv[1];
  int port=atoi(argv[2]);
  int sock;
  sock=creatSocket(ip,port);
  if(sock == -1){
    perror("socket()");
    exit(EXIT_FAILURE);
  }
  for(int i=0; i < 3;i++){
    printf("%d\n",i );
    int connection=acceptConnection(sock);
    if(connection == -1){
      break;
    }
  }
  printf("closing server \n");
 close(sock);

  return 0;
}
