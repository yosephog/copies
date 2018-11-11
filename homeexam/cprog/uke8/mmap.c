#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/mman.h>
#include<string.h>


int main(int argc,char* argv[]){
   if(argc != 2){
     fprintf(stderr, "usage %s <message>\n",argv[1] );
     return 0;
   }
   int p=PROT_READ | PROT_WRITE;
   int flags=MAP_SHARED | MAP_ANONYMOUS;

   char* mem=mmap(NULL,512,p,flags,-1,0);
   if(mem ==  MAP_FAILED){
     perror("mmap()");
     exit(EXIT_FAILURE);
   }
   printf("Yay %p\n",mem );
   pid_t pid=fork();
   if(pid == -1){
     perror("fork()");
     exit(EXIT_FAILURE);
   }
   if(pid==0)/** child process **/
    {
      sleep(1);
      printf("print message %s\n",argv[1] );
      printf("print message from mem %s\n",mem );
      return 42;
    }
    else{
      strcpy(mem,argv[1]);
      int statues;
      wait(&statues);
      printf("exit statues %d\n",WEXITSTATUS(statues) );
    }
  return 0;
}
