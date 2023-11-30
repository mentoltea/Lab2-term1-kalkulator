#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read_args.h"
#include "system16.h"
#include "system8.h"
#include "system2.h"
#include "decimal_funcs.h"



char* itoa(int decimal) {
    if (decimal==0) {
        char *result = (char*)malloc(1*sizeof(char));
        result[0] = '0';
        return result;
    }
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


char* solve(char* arg1, char* arg2, char operation) {
    if (arg2 == NULL && operation != '~') {
        printf("%c is not a unar operation!\n", operation);
        exit(1);
    }
    while (*arg1==' ') {
        arg1 += 1;
    }
    char* result;
    char arg1_type, arg2_type;
    int temp = 1;
    if (*arg1=='-') {
        temp += 1;
    }
    if (strlen(arg1+temp-1) == 1) {
        arg1_type = 'b';
    } else {
        arg1_type = arg1[temp];
        if (arg1_type!='x') {
            temp -=1;
            arg1_type = arg1[temp];
            if (arg1_type!='0') {
                arg1_type='b';
            }
        }
    }


    if (arg2 != NULL) {
        while (*arg2==' ') {
            arg2 += 1;
        }
        temp = 1;
        if (*arg2=='-') {
            temp += 1;
        }
        if (strlen(arg2+temp-1) == 1) {
            arg2_type = 'b';
        } else {
            arg2_type = arg2[temp];
            if (arg2_type!='x') {
                temp -=1;
                arg2_type = arg2[temp];
                if (arg2_type!='0') {
                    arg2_type='b';
                }
            }
        }

        if (arg1_type!=arg2_type) {
            printf("Cannot do math with different bases!(%c and %c)\n",arg1_type, arg2_type);
            exit(1);
        }
    }

    int dec1, dec2;
    if (arg2 == NULL) {
            dec2 = NULL;
    }
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
    if (solution==NULL) {
        printf("Not allowed to do binary operations to negative numbers!\n");
        exit(1);
    }
    
    if (operation == '&' || operation == '|' || operation == '^' || operation == '~') {
        printf("\narg1 bin -> %s\n", from10to2(dec1));
        if (dec2 != NULL) {
            printf("arg2 bin -> %s\n", from10to2(dec2));
        }
        printf("solution -> %s\n", from10to2(solution));
    }

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
    //int d1 = 432;
    //int d2 = 345;
    //printf("%s\n%s\n%s\n", from10to2(d1), from10to2(d2), from10to2(d1 | d2));
    //return;
    char* input = NULL;
    size_t len = 0;
    char* operations = "+*%%&|^~-";
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