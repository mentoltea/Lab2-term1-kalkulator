#include "system8.h"

int from8to10(char* arg) {
    while (*arg==' ') {
        arg += 1;
    }
    int koef=1;
    if (*arg == '-') {
        arg += 1;
        koef = -1;
    }
    char* ptr = arg + strlen(arg)-1;
    arg = arg+1;
    int sum = 0;
    int power = 0;
    char* alphabet = "01234567";
    for (int i=0; i<strlen(arg); i++) {
        if (arg[i] == ' ' || arg[i] == '\0') {continue;}
        int flag = 1;
        for (int j=0; j<8; j++) {
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
        if (*ptr != ' ' && *ptr != '\0') {
            sum += pow(8, power) * (strchr(alphabet, *ptr) - alphabet);
            power += 1;
            ptr -= 1;
        }
    }
    return sum*koef;
}

char* from10to8(int decimal) {
    int koef = 0;
    if (decimal<0) {koef=1; decimal*=-1;}
    char* alphabet = "01234567";
    
    int n=1;
    while (decimal / pow(8, n) > 0) {
        n+=1;
    }
    char* result = (char*) malloc((n+koef+1)*sizeof(char));
    result[n+koef+1]='\0';
    int last = 0;
    if (koef) {
        result[last]='-';
        last += 1;
    }
    
    result[last]='0'; result[last+1]='x';
    last+=2;

    int end = n+koef;
    while (decimal>0){
        result[end] = alphabet[ decimal%8 ];
        decimal /= 8;
        end -= 1;       
    }
    return result;
}