#ifndef READ_ARGS_FUNCS
#define READ_ARGS_FUNCS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

char** filter_args(char* input, size_t len, char* operations, size_t operations_len);


#endif