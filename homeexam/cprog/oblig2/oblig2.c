#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int getFirstLine(FILE* fp){
   int tall;
   fread(&tall,sizeof(tall),1,fp);
   return tall;
}

int main(int argc,char* argv[]){
    if(argc < 2){
      fprintf(stderr, "argument requeired %s\n",argv[0] );
      return 0;
    }
    FILE* fp=fopen(argv[1],"r");
     if(fp==NULL){
       fprintf(stderr,"couldn't read file %s \n",argv[1]);
       return 0;
     }
     int tall=getFirstLine(fp); printf("the number of line %d\n",tall );
     int id; char flagg; int lengde; char modell[256];
  //   fscanf(fp,"%d%c%d%s",&id,&flagg,&lengde,modell);
     char value[8];
     fgets(value,8,fp);
     printf("the id is %s\n",value );

  /**   for(int i=0;i<tall;i++){
      fread(&id,sizeof(id),1,fp);
      fread(&flagg,sizeof(flagg),1,fp);
      fread(&lengde,sizeof(lengde),1,fp);
      fread(modell,sizeof(modell),1,fp);

     printf("%d-%c-%d\n",id,flagg,lengde );
   }**/
     fclose(fp);
  return 0;
}
