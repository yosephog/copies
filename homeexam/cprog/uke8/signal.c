#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

void handler(int sig){
  printf("signum %d\n",sig );
}
int main(void){
  struct sigaction sg;
  memset(&sg,0,sizeof(struct sigaction));
  sg.sa_handler=handler;

  if(sigaction(SIGINT,&sg,NULL) == -1){
     perror("sigaction()");
     exit(EXIT_FAILURE);
  }
  int second=5;

  printf("Waiting.....\n" );
  while(second > 0){
    errno=0;
    second=sleep(second);
    if(errno == EINTR)
      printf("Interrupted :) \n" );
  }
  sleep(100);
}
