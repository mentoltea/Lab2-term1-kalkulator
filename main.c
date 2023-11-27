#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read_args.h"
#include "system16.h"
#include "system8.h"
#include "system2.h"
#include "decimal_funcs.h"



char* itoa(int decimal) {
    int koef = 0;
    if (decimal<0) {koef=1; decimal*=-1;}
    char* alphabet = "0123456789";
    
    int n=1;
    while (decimal / pow(10, n) > 0) {
        n+=1;
    }
    char *result = (char*)malloc((n+koef)*sizeof(char));
    result[n+koef]='\0';
    int last = 0;
    if (koef) {
        result[last]='-';
        last += 1;
    }

    int end = n+koef-1;
    while (decimal>0){
        result[end] = alphabet[ decimal%10 ];
        decimal /= 10;
        end -= 1;       
    }
    return result;
}

char* unar(char* arg, char operation) {
    if (operation != '~') {
        printf("%c is not a unar operation!\n", operation);
        exit(1);
    }
    while (*arg==' ') {
        arg += 1;
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
    } else if (arg_type=='0') {
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

    char* solstr = itoa(solution);
    char* res = (char*)malloc(sizeof(char)*(strlen(result)+strlen(solstr)+2+2));
    memcpy(res, result, strlen(result));
    res[strlen(result)] = ' ';
    res[strlen(result)+1] = '(';
    memcpy(res+strlen(result)+2, solstr, strlen(solstr));
    res[strlen(result)+2+strlen(solstr)] = ')';
    res[strlen(result)+2+strlen(solstr)+1] = '\0';

    return res;

}

char* solve(char* arg1, char* arg2, char operation) {
    if (arg2 == NULL) {
        return unar(arg1, operation);
    }
    while (*arg1==' ') {
        arg1 += 1;
    }
    while (*arg2==' ') {
        arg2 += 1;
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

    char* solstr = itoa(solution);
    char* res = (char*)malloc(sizeof(char)*(strlen(result)+strlen(solstr)+2+2));
    memcpy(res, result, strlen(result));
    res[strlen(result)] = ' ';
    res[strlen(result)+1] = '(';
    memcpy(res+strlen(result)+2, solstr, strlen(solstr));
    res[strlen(result)+2+strlen(solstr)] = ')';
    res[strlen(result)+2+strlen(solstr)+1] = '\0';
    //printf("%s\n", solstr);
    //printf("%s\n", res);
    return res;
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
    printf("\n");
    printf("arg1: %s\noperand: %c\narg2: %s\n", arg1, operation, arg2);
    printf("\n");

    char* result = solve(arg1, arg2, operation);
    printf("\n= %s\n", result);
    printf("\nEnd\n");
    return 0;
}