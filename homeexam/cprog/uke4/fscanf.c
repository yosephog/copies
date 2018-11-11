#include<stdio.h>
#include<stdlib.h>

int main(int argc,char* argv[]){

  if(argc < 2){
    fprintf(stderr,"file needed at %s \n",argv[0]);
    return 0;
  }
  FILE* fp=fopen(argv[1],"r");
  if(fp==NULL){
    fprintf(stderr,"couldn't read fil %s \n",argv[1]);
    return 0;
  }
  char a,b;  int num;
  fscanf(fp,"%c%c%d",&a,&b,&num);
  printf("%c%d\n",a,num);

  fclose(fp);
  return 0;
}
