#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main(void){
  long page_size =sysconf(_SC_PAGESIZE);
  printf("page size %ld\n",page_size );
  key_t key=42; //ipcs -m to see shared memory keys in terminal
  int id=shmget(key,512,IPC_CREAT | 0666);
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
   char buf[256]={0};
   while(1){
     printf("message please\n");
     if(fgets(buf,sizeof(buf),stdin)== NULL)
       break;
      strcpy(mem,"M");
      strcat(mem,buf);
    printf("Mem: %s\n",mem );
   }
   strcpy(mem,"E");
   printf("%s\n",buf );
   shmdt(mem);
  return 0;
}
