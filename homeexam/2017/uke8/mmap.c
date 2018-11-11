#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <string.h>

int main(int argc,char* argv[]){
  if(argc != 2){
    fprintf(stderr, "usage: %s <message>\n",argv[0] );
    return 0;
  }
  int protection=PROT_READ | PROT_WRITE;
  int flags=MAP_SHARED | MAP_ANONYMOUS;
  char* mymap=mmap(NULL,512,protection,flags,-1,0);
  if(mymap == MAP_FAILED){
    perror("mmap()");
    exit(EXIT_FAILURE);
  }
  printf("it is in %s \n",mymap);
  pid_t pid=fork();
  if(pid == -1){
    perror("fork()");
    exit(EXIT_FAILURE);
  }
  if (pid == 0){ // child process
    sleep(1);
    printf("Message first child %s\n",mymap);
      printf("Message first child %s\n",argv[1] );
  /**  pid_t second=fork();
    if(second == -1){
      perror("fork()");
      exit(EXIT_FAILURE);
    }
    if(pid==0){ // barn
      printf("Message from second child is %s \n",argv[1]);
      return 12;
    }
    else{ // parent
      int status;
      wait(&status);
      printf("exit status %d\n",WEXITSTATUS(status) );
    }**/

    return 2;
  }
  else{ // parent process
    printf("am in parent process \n");
    strcpy(mymap,argv[1]);
    int status;
    wait(&status);
    printf("child terminated with status %d\n",WEXITSTATUS(status) );
  }
  return 0;
}
