#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(void){
  /*  char filename[32];
    sprintf(filename,"%d",23456);
    FILE* fp=fopen(filename,"w+");
    fread(filename,sizeof(filename),1,fp);
    printf("%s\n",filename );
    fclose(fp);**/
   int a; pid_t pids[3];
   int tal=0;
   int statues;
   for(int i=0;i<3;i++){
     a=fork();
     if(!a) break;
     pids[i]=getpid();
   }
    if(a){


      for(int i=0;i<3;i++){
        waitpid(pids[i],&statues,0);
        tal+=i;
        printf("printing from parent %d\n",pids[i] );
      }
    //  printf("printing from parent outsideloop %d\n",tal );
    }
    else{
      for(int j=0;j<3;j++){
        tal+=1;
        printf("printing from child %d\n",getpid());
    }
    return tal;
    }
    return 0;
}
