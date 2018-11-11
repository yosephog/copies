#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>



int main(int argc,char* argv[]){
  if(argc != 2){
    fprintf(stderr,"usage %s <filename> \n",argv[0]);
    return 0;
  }
  int flags=O_WRONLY | O_CREAT;
  mode_t mode=S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
  mode_t mod=S_IRWXU;
  int fd=open(argv[1],flags,mode);
  if(fd == -1){
    perror("open()");
    exit(EXIT_FAILURE);
  }
  printf("O_WRONLY: %d\n",O_WRONLY);
  printf("O_CREAT: %d\n",O_CREAT);
  printf("flags: %d",flags);

  printf("Yay\n");
   char* txt="hello world :) \n";
  write(fd,txt,strlen(txt));
  close(fd);
  return 0;
}
