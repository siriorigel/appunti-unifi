#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N 20

int main(){
    char s[N], k[N];
    unsigned int len = 0;
    int m=0;

    printf("Inserisci una stringa di caratteri: \n");
    scanf(" %s", s);

    len = strlen(s);

    for (int i = len-1; i >= 0; i--)
    {
        k[m]= s[i];
        printf(" %c \n", k[m]);
        m++;
    }

    printf("%s \n", k);

}