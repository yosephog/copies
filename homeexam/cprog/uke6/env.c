#include<stdio.h>

extern char** environ;

int main(int argc,char* argv[],char* envp[]){
  char usr[32];

   

#if 0
   for(int i=0;envp[i] != NULL;i++){
     printf("envp[%d]= %s\n", i , envp[i]);
   }
  #else
   for(int i=0;environ[i] != NULL;i++){
     printf("environ[%d]= %s\n", i , environ[i]);
   }

   return 0;
}
