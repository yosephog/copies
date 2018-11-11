#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){
  long page_size =sysconf(_SC_PAGESIZE);
  printf("page size %ld\n",page_size );
  key_t key=42;
  int id=shmget(key,512,0666);
   if(id==-1){
     perror("shmget()");
     exit(EXIT_FAILURE);
   }
   char *mem=shmat(id,NULL,0);
   if(mem==(void*)-1){
     perror("shmat()");
     exit(EXIT_FAILURE);
   }
   printf("Success: %p\n",mem );
   char buf[256];
   while(1){
     char type=*mem;
     if(type == 'M'){
       if(strcmp(mem,buf+1)){
          strncpy(buf,mem+1,sizeof(buf)-1);
          printf("Recived : %s\n",buf );
       }
     }
     else if(type== 'E'){
       break;
     }
     else{
       fprintf(stderr, "Unkown Option %c\n",type );
     }

   }

   shmdt(mem);
  return 0;
}
