#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc , char* argv[]){
   if(argc < 2){
     fprintf(stderr,"file needed at %s \n",argv[0]);
     return 0;
   }
   FILE* fp=fopen(argv[1],"r");
   if(fp==NULL){
     fprintf(stderr,"couldn't read fil %s \n",argv[1]);
     return 0;
   }
    int num;
    fread(&num,sizeof(num),1,fp);
    printf("the number read from file is %d\n",num );
    fclose(fp);
  return 0;
}
