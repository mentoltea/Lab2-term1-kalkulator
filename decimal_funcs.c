#include "decimal_funcs.h"

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