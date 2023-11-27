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


char* unar(char* arg, char operation) {
    if (operation != '~') {
        printf("%c is not a unar operation!\n", operation);
        exit(1);
    }
    char* result;
    char arg_type;
    int temp = 1;
    if (*arg=='-') {
        temp += 1;
    }
    arg_type = arg[temp];
    if (arg_type!='x') {
        temp -=1;
        arg_type = arg[temp];
        if (arg_type!='0') {
            arg_type='b';
        }
    }
    
    int dec;
    if (arg_type=='x'){
        dec = from16to10(arg);
    } else if (arg1_type=='0') {
        dec = from8to10(arg);
    } else {
        dec = from2to10(arg);
    }

    int solution = eval(dec, NULL, operation);

    if (arg_type=='x'){
        result = from10to16(solution);
    } else if (arg_type=='0') {
        result = from10to8(solution);
    } else {
        result = from10to2(solution);
    }
    return result;

}

char* solve(char* arg1, char* arg2, char operation) {
    if (arg2 == NULL) {
        return unar(arg1, operation);
    }
    char* result;
    char arg1_type, arg2_type;
    int temp = 1;
    if (*arg1=='-') {
        temp += 1;
    }
    arg1_type = arg1[temp];
    if (arg1_type!='x') {
        temp -=1;
        arg1_type = arg1[temp];
        if (arg1_type!='0') {
            arg1_type='b';
        }
    }

    temp = 1;
    if (*arg2=='-') {
        temp += 1;
    }
    arg2_type = arg2[temp];
    if (arg2_type!='x') {
        temp -=1;
        arg2_type = arg1[temp];
        if (arg2_type!='0') {
            arg2_type='b';
        }
    }

    if (arg1_type!=arg2_type) {
        printf("Cannot do math with different bases!(%c and %c)\n",arg1_type, arg2_type);
        exit(1);
    }

    int dec1, dec2;
    if (arg1_type=='x'){
        dec1 = from16to10(arg1);
        dec2 = from16to10(arg2);
    } else if (arg1_type=='0') {
        dec1 = from8to10(arg1);
        dec2 = from8to10(arg2);
    } else {
        dec1 = from2to10(arg1);
        dec2 = from2to10(arg2);
    }

    int solution = eval(dec1, dec2, operation);

    if (arg1_type=='x'){
        result = from10to16(solution);
    } else if (arg1_type=='0') {
        result = from10to8(solution);
    } else {
        result = from10to2(solution);
    }
    return result;
}


int main() {
    char* input = NULL;
    size_t len = 0;
    char* operations = "+-*%%&|^~";
    size_t operations_len = sizeof(operations)/sizeof(char)+1;

    printf("Enter expression:\n");
    len = getline(&input, &len, stdin) - 1;

    char** argv = filter_args(input, len, operations, operations_len);
    char* arg1 = argv[0];
    char* arg2 = argv[2];
    char operation = *argv[1];
    for (int i=0; i<3; i++) {
        printf("%d: %s\n", i, argv[i]);
    }   

    char* result = solve(arg1, arg2, operation);
    printf("= %s\n", result);
    printf("\nEnd\n");
    return 0;
}