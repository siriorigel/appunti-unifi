#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int a, b;
    
    // Input due numeri interi
    printf("Inserisci due numeri interi a e b: ");
    scanf("%d %d", &a, &b);

    // Controlla se b è positivo o negativo
    if (b < 0) {
        printf("b è un numero negativo \n");
    } else {
        printf("b è un numero positivo \n");        
    }

    // Controlla se a è pari o dispari
    if (a % 2 != 0) {
        printf("a è dispari! \n");
    } else {
        printf("a è pari! \n");
    }

    // Calcola il valore assoluto della differenza tra a e b
    int c = abs(a - b);

    // Stampa il valore massimo di a-b
    printf("Il valore massimo di a-b è: %d \n", c);    
        
    return 0;
}
