#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N 20

int main(){
    char s1[N];
    
    // Input della stringa
    scanf("%s", s1);
    
    unsigned int l;

    // Calcola la lunghezza della stringa
    l = strlen(s1);

    // Stampa la lunghezza della stringa
    printf("%d \n", l);
}
