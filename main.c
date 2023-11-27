#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include "read_args.h"
#include "system16.h"
#include "system8.h"
#include "system2.h"
#include "decimal_funcs.h"



int main() {
    printf("%d", ~3);
    return;
    char* input = NULL;
    size_t len = 0;
    char* operations = "+-*%%&|^~";
    size_t operations_len = sizeof(operations)/sizeof(char)+1;

    printf("Enter expression:\n");
    len = getline(&input, &len, stdin) - 1;

    char** argv = filter_args(input, len, operations, operations_len);

    for (int i=0; i<3; i++) {
        printf("%d: %s\n", i, argv[i]);
    
    }   
    printf("\nEnd\n");
    return 0;
}