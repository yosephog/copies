#include<stdio.h>
#include<stdlib.h>

#define FIRST

int main(int argc,char* argv[]){

   if(argc < 3){
     fprintf(stderr, "need file name and a number to be written%s\n",argv[0] );
     return 0;
   }
   FILE* fp=fopen(argv[1],"w+");
   if(fp==NULL){
     fprintf(stderr, "couldn't open or create file %s\n",argv[1] );
     return 0;
   }
#if 1
  // using atoi
   int num=atoi(argv[2]);
   fwrite(&num,sizeof(num),1,fp);
#else
 // usit strtol
   char** pt=malloc(sizeof(int));
   int num2=strtol(argv[2],pt,10);
   fwrite(&num2,sizeof(num),1,fp);




   fclose(fp);
  return 0;
}
