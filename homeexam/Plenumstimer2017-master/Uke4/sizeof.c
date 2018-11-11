#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STR "split me;please"

char *strtok_simple_internal_pointer = NULL;

char *strtok_simple(char* split_me, char* delim) {
#ifdef DEBUG
    printf("______ START STRTOK_SIMPLE ______\n");
    printf("split_me: %s\n", split_me);
#endif

    if(!strtok_simple_internal_pointer) {
        strtok_simple_internal_pointer = split_me;
    }
    // finne mellomrom
    unsigned int i;
    char* closest = NULL;
    for (i = 0; i < strlen(delim); i++) {
        if(!closest) {
            closest = strchr(strtok_simple_internal_pointer, delim[i]);
        } else {
            char *this_delim = strchr(strtok_simple_internal_pointer, delim[i]);
            if(this_delim < closest) {
                closest = this_delim;
            }
        }
    }

    // erstatt med null-byte
    if(!closest) {
        return NULL;
    }
    *closest = '\0';

#ifdef DEBUG
    printf("split_me: %s\n", split_me);
    printf("______ END   STRTOK_SIMPLE ______\n");
#endif

    // returner pekeren
    char* ret = strtok_simple_internal_pointer;
    strtok_simple_internal_pointer = closest + 1;
    return ret;
}

int main() {

    char *to_be_split = strdup(STR);
    char *token;

    printf("size of str: %zu\n", sizeof(to_be_split));
    printf("length of str: %zu\n", strlen(to_be_split));

    token = strtok(to_be_split, " ;");
    //etter strtok nr 1:
    //"Split\0me please";
    if(token) {
        printf("%s\n", token);
    }

    token = strtok(NULL, " ;");
    //etter strtok nr 1:
    //"Split\0me\0please";
    if(token) {
        printf("%s\n", token);
    }

    token = strtok(NULL, " ;");
    //etter strtok nr 1:
    //"Split\0me\0please";
    if(token) {
        printf("%s\n", token);
    }

    free(to_be_split);
    to_be_split = strdup(STR);

    printf("string before: %s\n", to_be_split);

    to_be_split = strtok_simple(to_be_split, " ;");
    if(to_be_split) {
        printf("string after: %s\n", to_be_split);
    }

    to_be_split = strtok_simple(NULL, " ;");
    if(to_be_split) {
        printf("string after: %s\n", to_be_split);
    }
}


