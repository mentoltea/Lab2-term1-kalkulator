#ifndef READ_ARGS_FUNCS
#define READ_ARGS_FUNCS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char** filter_args(char* input, size_t len, char* operations, size_t operations_len);

char* substr(char* str, size_t from, size_t to);

#endif