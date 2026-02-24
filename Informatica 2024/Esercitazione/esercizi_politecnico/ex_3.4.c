#include <stdio.h>
#include <math.h>

int main() {
    double n;
    
    // Input del numero
    printf("Inserisci un numero: \n");
    scanf("%lf", &n);

    // Calcola il valore assoluto del numero
    if (n < 0) {
        n = -n; // Se il numero è negativo, cambia il segno per ottenere il valore assoluto
    } else {
        n = n; // Se il numero è positivo o zero, il valore assoluto rimane lo stesso
    }

    // Stampa il valore assoluto del numero
    printf("Il valore assoluto del numero inserito è: %.3lf. \n", n);

    return 0;
}
