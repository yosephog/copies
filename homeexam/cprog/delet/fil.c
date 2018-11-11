#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char* argv[]){
  if(argc != 2){
    fprintf(stderr, "usage <message> %s\n",argv[0] );
    return 0;
  }
  //TODO test all

  FILE* fp=fopen(argv[1],"r");
  if(fp==NULL){
    perror("fopen()");
    exit(EXIT_FAILURE);
  }
  char buf[20]={0};

  fgets(buf,sizeof(buf),fp);
  printf("%s\n", buf);


  fclose(fp);
  return 0;
}
