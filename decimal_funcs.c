#include "decimal_funcs.h"

size_t pow(size_t base, size_t power) {
    size_t p = 1;
    for (int i=0; i<power; i++) {
        p*=base;
    }
    return p;
}

int eval(int arg1, int arg2, char operation) {
    switch (operation)
    {
    case '+':
        return arg1 + arg2;

    
    case '-':
        return arg1 - arg2;

    
    case '*':
        return arg1 * arg2;

    
    case '%':
        return arg1 % arg2;

    
    case '&':
        return arg1 & arg2;


    case '|':
        return arg1 | arg2;

    
    case '^':
        return arg1 ^ arg2;

    
    case '~':
        return ~arg1;
        break;
    

    
    default:
        break;
    }
}