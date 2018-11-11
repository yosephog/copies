#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMN_LEN 100

void systmcall(int argc,char* argv[]){
  char cmd[MAX_CMN_LEN] = "", **p;

  if (argc < 2) /*no command specified*/
  {
      fprintf(stderr, "Usage: ./program_name terminal_command ...");
      exit(EXIT_FAILURE);
  }
  else
  {
      strcat(cmd, argv[1]);
      for (p = &argv[2]; *p; p++)
      {
          strcat(cmd, " ");
          strcat(cmd, *p);
      }
      system(cmd);
  }
}
void print_binary(int num)
{
	int pos = (sizeof(int) * 8) - 1;
	printf("%10d: ", num);

	for (int i = 0; i < (int)(sizeof(int) * 8); i++) {
		char c = num & (1 << pos) ? '1' : '0';
		putchar(c);
		if (!((i + 1) % 8))
			putchar(' ');
		pos--;
	}
	putchar('\n');
}
int main(int argc, char *argv[])
{
  char a='a';
  int aa=(int)a;
  printf("%d\n",aa );
  print_binary(aa);
  return 0;
}
