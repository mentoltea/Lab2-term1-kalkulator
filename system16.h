#ifndef SYSTEM16_FUNCS
#define SYSTEM16_FUNCS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

char* system16(char* arg1, char* arg2, char operation);

char* sum16(char* arg1, char* arg2);

char* sub16(char* arg1, char* arg2);

char* mul16(char* arg1, char* arg2);

char* moddiv16(char* arg1, char* arg2);

char* tobinary16(char* arg);

char* bitand16(char* arg1, char* arg2);

char* bitor16(char* arg1, char* arg2);

char* bitxor16(char* arg1, char* arg2);

char* bitnot16(char* arg);

#endif