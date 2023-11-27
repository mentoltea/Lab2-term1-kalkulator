#ifndef SYSTEM2_FUNCS
#define SYSTEM2_FUNCS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

char* system2(char* arg1, char* arg2, char operation);

char* sum2(char* arg1, char* arg2);

char* sub2(char* arg1, char* arg2);

char* mul2(char* arg1, char* arg2);

char* moddiv2(char* arg1, char* arg2);

char* bitand2(char* arg1, char* arg2);

char* bitor2(char* arg1, char* arg2);

char* bitxor2(char* arg1, char* arg2);

char* bitnot2(char* arg);

#endif