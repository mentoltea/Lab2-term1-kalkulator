#include "system16.h"


int from16to10(char* arg) {
    printf("%s ->", arg);
    while (*arg==' ') {
        arg += 1;
    }
    int koef=1;
    if (*arg == '-') {
        arg += 1;
        koef = -1;
    }
    char* ptr = arg + strlen(arg)-1;
    arg = arg+2;
    int sum = 0;
    int power = 0;
    char* alphabet = "0123456789abcdef";
    for (int i=0; i<strlen(arg); i++) {
        if (arg[i] == ' ' || arg[i] == '\0' || arg[i] =='\n') {continue;}
        int flag = 1;
        for (int j=0; j<16; j++) {
            if (arg[i] == alphabet[j]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            printf("The letter %c is out of hex system!\n");
            exit(1);
        }
    }
    while (ptr != arg-1) {
        if (*ptr != ' ' && *ptr != '\0' && *ptr != '\n') {
            sum += pow(16, power) * (strchr(alphabet, *ptr) - alphabet);
            power += 1;
        }
        ptr -= 1;
    }
    printf(" %d\n", sum*koef);
    return sum*koef;
}

char* from10to16(int decimal) {
    int koef = 0;
    if (decimal<0) {koef=1; decimal*=-1;}
    char* alphabet = "0123456789abcdef";
    
    int n=1;
    while (decimal / pow(16, n) > 0) {
        n+=1;
    }
    char *result = (char*)malloc((n+2+koef)*sizeof(char));
    result[n+2+koef]='\0';
    int last = 0;
    if (koef) {
        result[last]='-';
        last += 1;
    }
    
    result[last]='0'; result[last+1]='x';
    last+=2;

    int end = n+1+koef;
    while (decimal>0){
        result[end] = alphabet[ decimal%16 ];
        decimal /= 16;
        end -= 1;       
    }
    return result;
}