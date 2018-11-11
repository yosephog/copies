#ifndef __UTIL_H
#define __UTIL_H

enum DEBUG_LEVELS {
    ERR_LEVEL,
    WARN_LEVEL,
    INFO_LEVEL,
};

union test {
    int i;
    float f;
    char s[20];
};

#define INFO_STRING "INFO"
#define WARN_STRING "WARN"
#define ERR_STRING  " ERR"

#define DEBUG_TYPE_STRING_LEN 5
#define DEBUG_TYPES 3

void debug_print(int msg_leve, char* print_string);

#endif
