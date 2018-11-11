#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc,char* argv[]){

   char** array=malloc(sizeof(char* ) * (argc +1));
   for(int i=0;i<argc;i++){
     array[i]=malloc(strlen(argv[i])+1);
     strcpy(array[i],argv[i]);
   }
   for(int i=0;i<argc; i++){
     printf("value [%d] -: %s \n",i,array[i]);
   }
   for(int i=0;i<argc;i++){
      free(array[i]);
   }
   free(array);
  return 0;
}
