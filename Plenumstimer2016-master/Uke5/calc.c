#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

#define CHILDREN 3
#define RANGE 1000
#define filewrite

pid_t children[CHILDREN];

int main() {
	int start = 1;
	int a;

	for (int i = 0; i < CHILDREN; i++) {
		a = fork();
		if(!a) break;
		children[i] = a;
		start += RANGE;
	}

	if (a) {
		int status;
		int sum = 0;
		for (int i = 0; i < CHILDREN; i++) {
			waitpid(children[i], &status, 0);
			printf("exit status of child %d: %d\n", children[i], status);

#ifdef filewrite
			char file_name[32];
			sprintf(file_name, "%d", children[i]); 
			FILE* fp = fopen(file_name, "r");
			int temp = 0;
			fread(&temp, sizeof(int), 1, fp);
			sum += temp;
			fclose(fp);
#else
			sum += status;
#endif
		}
		printf("sum: %d\n", sum);
		
	} else {
		char file_name[32];
		sprintf(file_name, "%d", getpid()); 
		FILE* fp = fopen(file_name, "w+");
		if (!fp) {
			perror("fopen()");
			return EXIT_FAILURE;
		}
		int res = 0;
		for (int i = start; i < start+RANGE; i++) {
			res += i;
		}
		fwrite(&res, sizeof(int), 1, fp);
		fclose(fp);
		printf("%d\n", res);
		return res;
	}
}

