#include <stdio.h>
#include <stdlib.h>

 /*
 * fgetc
 * fgets
 * getc
 * fwrite
 * fread
 * fprintf
 * sprintf
 */

void myFgetc(FILE* fp){

    int input=fgetc(fp);
   while(input != EOF){
    printf("%c",(char) input );
    input=fgetc(fp);
   }
  fclose(fp);
}

void myFgets(FILE* fp){

  char buf[256];
while(fgets(buf,sizeof(buf)-1,fp)){
  printf("%s",buf );
}

}
int main(void){

  FILE* fp=fopen("myfile","r");
  myFgets(fp);

  return 0;
}
