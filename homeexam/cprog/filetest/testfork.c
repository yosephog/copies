#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

#define CHILDREN 3
#define RANGE 1000
pid_t pidarray[CHILDREN];

int main(void){
   int a;
   int start=1; int sum=0;
    for(int i=0;i<CHILDREN;i++){
      a=fork();
      if(!a)
        break;
      pidarray[i]=a;
      start+=RANGE;
    }
    int statues;
    if(a){
      for(int i=0;i<CHILDREN;i++){
      waitpid(pidarray[i],&statues,0);
      printf("exit statues of children %d %d \n",pidarray[i],statues);
      char filename[32];
      sprintf(filename,"%d",pidarray[i]);
      FILE* fp=fopen(filename,"r");
      int temp=0;
      sum+=temp;
      fclose(fp);
    }
    }
    else{
       char file_name[32];
       sprintf(file_name,"%d",getpid());
       FILE* fp=fopen(file_name,"w+");
       int res=0;
       for(int i=start;i<start+RANGE;i++){
         res+=i;
       }
       fwrite(&res,sizeof(res),1,fp);
       fclose(fp);
    }
  return 0;
}
