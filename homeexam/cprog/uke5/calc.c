#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

#define CHILDREN 3
#define RANGE 1000
pid_t children[CHILDREN];
int main(void){
   int start=1;
   int a;
  for(int i=0;i<CHILDREN;i++){
      a=fork();
     if(!a)break;
     children[i]=a;
     start+=RANGE;
  }
    if(a){
      int sum=0;
      int statue;
       for (int i=0; i < CHILDREN;  i++) {
         waitpid(children[i],&statue,0);
         printf("exit statues of children %d: %d \n",children[i],statue);
         char fil[32];
         sprintf(fil,"%d",children[i]);
        FILE* fp= fopen(fil,"r");
        int temp=0;
        fread(fil,sizeof(fil),1,fp);
        sum+=temp;
        sum+=statue;
        fclose(fp);
       }
       printf("the sum is sum-:%d\n",sum );
    }
    else{
      char file_name[32];
      sprintf(file_name,"%d",getpid());
      FILE* fp=fopen(file_name,"w+");
      if(!fp){
        perror("fopen()");
        return -1;
      }
      int res=0;
      for(int i=start;i<start+RANGE;i++){
        res+=i;
      }
      fwrite(&res,sizeof(res),1,fp);
      fclose(fp);
    //  printf("the res is %d\n",res );
      return res;
    }


 return 0;
}
