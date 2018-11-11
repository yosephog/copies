#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

#define MESSAGE_SIZE 256
#define REPLY_SIZE 256

int read_message(int fd, int* operator, int* a, int* b);
int send_message(int fd, int error, int res);
