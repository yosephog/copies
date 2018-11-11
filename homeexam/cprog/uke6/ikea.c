#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {

  char name[256];
  int price;
  unsigned char id;

}items;

items* item[256];
void read_antall(FILE* fp,int* tall){
   fread(tall,sizeof(int),1,fp);
}
void check_newline(FILE* fp){
  int c=fgetc(fp);
  if(c != '\n'){
     fprintf(stderr, "expected new line go 0x%x (%d)\n",c,c );
     fclose(fp);
     exit(EXIT_FAILURE);
  }
}
void strip_newline(char* s){
  char* ptr=strchr(s,'\n');
  if(ptr != NULL)
    *ptr='\0';
}
void print_item(items* ite){
  printf("%s - %d - %c \n",ite->name,ite->price,ite->id );
}
int main(int argc,char* argv[]){

   if(argc < 2){
     fprintf(stderr,"usage <filename> %s \n",argv[0]);
      exit(EXIT_FAILURE);
   }
   FILE* fp=fopen(argv[1],"r");
    if(fp==NULL){
      perror("fopen()");
      exit(EXIT_FAILURE);
    }
    int antall=0;
    read_antall(fp,&antall);
    printf("the numer of objects is %d\n",antall );
    check_newline(fp);
   item[antall]=NULL;
    for(int i=0;i<antall;i++){
      char name[256];
      memset(name,0,sizeof(name));
      fgets(name,sizeof(name),fp);
      strip_newline(name);
      int price;
      read_antall(fp,&price);
      check_newline(fp);

      unsigned char id;
      fread(&id,sizeof(id),1,fp);
      check_newline(fp);
     item[i]=malloc(sizeof(items));
    // items* it=item[i];
      strcpy(item[i]->name,name);
      item[i]->price=price;
      item[i]->id=id;
      print_item(item[i]);

    }
    for(int i=0;i<antall;i++){
      free(item[i]);
    }
    fclose(fp);
  return 0;
}
