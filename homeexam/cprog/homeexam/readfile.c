#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct jobb{
  unsigned char jobbInfo;
  unsigned int textLengde;
   char jobbtekst[];
};

int main(int argc,char* argv[]){

  if(argc != 2){
    fprintf(stderr, "usage <filename> %s\n",argv[0] );
    return 0;
  }
  FILE* fp=fopen(argv[1],"r");
  struct jobb* jobber=malloc(sizeof(struct jobb));

    int x=fgetc(fp);
    jobber->jobbInfo=(unsigned char)x;
    jobber->textLengde=fgetc(fp);
     char buf[77]={0};
     //fread(buf,76,1,fp);
     fscanf(fp,"%s",buf);
    printf("JobbInfo --> %c\n",jobber->jobbInfo);
    printf("JobbLengde --> %d\n",jobber->textLengde );
    printf("Text--> %s\n",buf );
  return 0;
}
