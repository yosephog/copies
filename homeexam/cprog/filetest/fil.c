#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
  unsigned char id; char flagg;
  unsigned char lengde; char modell[253];
}ruter;
ruter* mainrutter[10];
int counter;

void printout(){

   for(int i=0;mainrutter[i] != NULL ;i++){
     printf("%x %x %x %s\n",mainrutter[i]->id,mainrutter[i]->flagg,
           mainrutter[i]->lengde,mainrutter[i]->modell);
   }
}

int print_info_givenid(int ide){
  for(int i=0;mainrutter[i] != NULL;i++){
     if(mainrutter[i]->id == ide){
       printf("printing out info of given id -: %d\n",ide );
       printf("%x %x %x %s\n",mainrutter[i]->id,mainrutter[i]->flagg,
             mainrutter[i]->lengde,mainrutter[i]->modell );
             return 0;
     }
  }
  printf("no such id is found \n" );
  return -1;
}
int chang_flag(int ide,char flag){
  for(int i=0;mainrutter[i] != NULL;i++){
     if(mainrutter[i]->id == ide){
       mainrutter[i]->flagg=flag;
             return 0;
     }
  }
  return -1;
}
int main(int argc,char* argv[]){
   if(argc < 2){
      fprintf(stderr, "file name needed as argument %s\n",argv[0] );
      return -1;
   }
   FILE* fp=fopen(argv[1],"r");
   if(fp==NULL){
      fprintf(stderr, "couldn't read the file %s\n",argv[1] );
      return -1;
   }
   int ruter_length;  fread(&ruter_length,sizeof(int),1,fp);
   printf("the length of the ruter is -: %d \n",ruter_length);

   ruter* myruter;
   int tempcounter=0;
   while(tempcounter < ruter_length){
      if(fgetc(fp) == '\n'){
        while(!feof(fp)){
     myruter=malloc(sizeof(ruter));
     myruter->id=fgetc(fp);
     myruter->flagg=fgetc(fp);
     myruter->lengde=fgetc(fp);
     fgets(myruter->modell,sizeof(myruter->modell),fp);
     mainrutter[counter]=myruter;
     //free(myruter);
     counter++;
    // printf("%x %x %x %s \n",myruter->id,myruter->flagg,
    //       myruter->lengde, myruter->modell);
         }
   }
   tempcounter++;
   }
   printout();
    chang_flag(1,'c');
   print_info_givenid(1);
  // chang_flag(1,'c');
   fclose(fp);
   //for(int i=0;i<ruter_length;i++)
      free(myruter);
  return 0;
}
