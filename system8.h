#ifndef SYSTEM8_FUNCS
#define SYSTEM8_FUNCS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

char* system8(char* arg1, char* arg2, char operation);

char* sum8(char* arg1, char* arg2);

char* sub8(char* arg1, char* arg2);

char* mul8(char* arg1, char* arg2);

char* moddiv8(char* arg1, char* arg2);

char* tobinary8(char* arg);

char* bitand8(char* arg1, char* arg2);

char* bitor8(char* arg1, char* arg2);

char* bitxor8(char* arg1, char* arg2);

char* bitnot8(char* arg);

#endif