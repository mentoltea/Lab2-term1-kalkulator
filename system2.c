#include "system2.h"

int from2to10(char* arg) {
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
        if (arg[i] == ' ' || arg[i] == '\0') {continue;}
        int flag = 1;
        for (int j=0; j<2; j++) {
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
            sum += pow(2, power) * (strchr(alphabet, *ptr) - alphabet);
            power += 1;
            ptr -= 1;
        }
    }
    return sum*koef;
}

char* from10to2(int decimal) {
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