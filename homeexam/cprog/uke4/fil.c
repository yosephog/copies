#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc,char* argv[]){

   if(argc != 2){
     fprintf(stderr, "file name needed %s\n",argv[0] );
     return 0;
   }
   FILE* fil=fopen(argv[1],"r");
   if(fil == NULL){
     fprintf(stderr, "couldn't read file %s\n",argv[1] );
     return 0;
   }
   char buf[256];
   int line=0;
    while(fgets(buf,256,fil) != NULL){
      printf("line %d -: %s\n",line,buf );
      line++;
    }
    fclose(fil);
  return 0;
}
