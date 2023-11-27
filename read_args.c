#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include "read_args.h"

char* substr(char* str, size_t from, size_t to) {
    char* res = (char*)malloc(sizeof(char)*(to-from));
    for (int i=from; i<to; i++) {
        res[i-from] = str[i];
    }
    return res;
}


char** filter_args(char* input, size_t len, char* operations, size_t operations_len) {
    char* sep = NULL;
    for (int i = 0; i<operations_len; i++) {
        sep = strchr(input, operations[i]);
        if (sep != NULL) {
            if (*sep == '-' && sep==input){ continue; }
            break;
        }
    }
    if (sep==NULL) {
        printf("Supportable operation was not found\n");
        exit(1);
    }
    //printf("operation: %c\n", *sep);
    char** result = (char**)malloc(3*sizeof(char*));

    if (sep==input) {
        char* arg1;
        arg1 = substr(input, 1, strlen(input)-1);
        result[0] = arg1;

        char* operation[1];
        operation[0]=*sep;
        result[1] = operation;

        result[2] = NULL;
        return result;
    }
    else {
        char *arg1 = (char*) malloc((sep-input+1)*sizeof(char));
        char *arg2 = (char*) malloc(((input-sep)+len)*sizeof(char));

        arg1 = memcpy(arg1, input, (sep-input)*sizeof(char));
        arg1[sep-input+1]='\0';

        arg2 = memcpy(arg2, sep+1, ((input-sep)+len-1)*sizeof(char));
        if (strlen(arg2)==1) {
            printf("Arg2 is empty!\n");
            exit(1);
        }
        //printf("arg1: %s\narg2: %s\n", arg1, arg2);

        char* operation[1];
        operation[0]=*sep;
        
        result[0] = arg1;
        result[1] = operation;
        result[2] = arg2;
        return result;
    }
}
