#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main(void){
  int fds[2]; // 0 read 1 wright

  if(pipe(fds) == -1){
    perror("pipe()");
    exit(EXIT_FAILURE);
  }
  char* msg="read before the exam";

  pid_t pid=fork();

  if(pid == -1){
    perror("pipe()");
    exit(EXIT_FAILURE);
  }
  if(pid == 0){// child
    close(fds[1]);
    char buf[64]={0};
    read(fds[0],buf,sizeof(buf)-1);
    printf("%s\n",buf );
  }else{
    close(fds[0]);
    write(fds[1],msg,strlen(msg));
  }


  return 0;
}
