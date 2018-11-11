#include "util.h"
#include <stdio.h>
#include <unistd.h>

int debug_mode = 0;

char info_type_array[DEBUG_TYPES][DEBUG_TYPE_STRING_LEN] = { ERR_STRING, WARN_STRING, INFO_STRING };

void debug_print(int msg_level, char* print_string) {
    if(debug_mode > 0) {
        if(debug_mode >= INFO_LEVEL) {
            printf(">>>%d<<<[%s] %s\n", getpid(), info_type_array[msg_level-1], print_string);
        } else if(debug_mode >= WARN_LEVEL && msg_level <= WARN_LEVEL) {
            printf(">>>%d<<<[%s] %s\n", getpid(), info_type_array[msg_level-1], print_string);
        } else if(debug_mode >= ERR_LEVEL && msg_level <= ERR_LEVEL) {
            printf(">>>%d<<<[%s] %s\n", getpid(), info_type_array[msg_level-1], print_string);
        }
    }
}
