#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

int main(void){

   int fds[2]; // fds[0] for read fds[1] to write
   char *msg ="hei there du der";
   char buf[64]={0};
    if(pipe(fds)==-1){
      perror("pipe()");
      exit(EXIT_FAILURE);
    }
    printf("pipe is setup.....\n" );

    pid_t pid=fork();
    if(pid==-1){
      perror("fork()");
      exit(EXIT_FAILURE);
    }

   // fork parent write to child
    if(pid==0){// child
      close(fds[1]);
      read(fds[0],buf,sizeof(buf));
    }
    else{
      close(fds[0]);
      write(fds[1],msg,sizeof(msg));
    }
    printf("printing from buf %s\n",buf );

  return 0;
}
