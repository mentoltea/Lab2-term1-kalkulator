#include "system2.h"

int from2to10(char* arg) {
    if (arg == NULL) {
        return NULL;
    }
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
    int sum = 0;
    int power = 0;
    char* alphabet = "01";
    for (int i=0; i<strlen(arg); i++) {
        if (arg[i] == ' ' || arg[i] == '\0' || arg[i] == '\n') {continue;}
        int flag = 1;
        for (int j=0; j<2; j++) {
            if (arg[i] == alphabet[j]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            printf("The letter %c is out of bin system!\n");
            exit(1);
        }
    }
    while (ptr != arg-1) {
        if (*ptr != ' ' && *ptr != '\0' && *ptr != '\n') {
            sum += pow(2, power) * (strchr(alphabet, *ptr) - alphabet);
            power += 1;
        }
        ptr -= 1;
    }
    printf(" %d\n", sum*koef);
    return sum*koef;
}

char* from10to2(int decimal) {
    if (decimal==0) {
        char *result = (char*)malloc(1*sizeof(char));
        result[0]='0';
        return result;
    }
    int koef = 0;
    if (decimal<0) {koef=1; decimal*=-1;}
    char* alphabet = "01";
    
    int n=1;
    while (decimal / pow(2, n) > 0) {
        n+=1;
    }
    char* result = (char*) malloc((n+koef)*sizeof(char));
    result[n+koef]='\0';
    int last = 0;
    if (koef) {
        result[last]='-';
        last += 1;
    }
    
    //result[last]='0'; result[last+1]='x';
    //last+=2;

    int end = n+koef-1;
    while (decimal>0){
        result[end] = alphabet[ decimal%2 ];
        decimal /= 2;
        end -= 1;       
    }

    return result;
}


int bit_inverse(int decimal) {
    char* arg = from10to2(decimal);
    int arg_len = strlen(arg);
    printf("\n%s\n(inversion)->\n",arg);

    for (int i=0; i<arg_len; i++) {
        if (arg[i] == '0') {
            arg[i] = '1';
        } else {
            arg[i] = '0';
        }
    }

    while(*arg=='0' && arg_len>1) {
        arg+=1;
        arg_len-=1;
    }
    printf("%s\n\n",arg);
    return from2to10(arg);
}