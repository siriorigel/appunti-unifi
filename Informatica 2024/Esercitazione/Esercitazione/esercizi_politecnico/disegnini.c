#include <stdio.h>
#include <stdlib.h>

int main() {
    int a;
    // Input del numero di asterischi per lato
    printf("Inserisci il numero di asterischi per lato: ");
    scanf("%d", &a);

    // Verifica se il numero inserito è valido (positivo)
    if (a <= 0) {
        printf("ERRORE: Il numero deve essere positivo!\n");
    } else {
        // Genera il rettangolo di asterischi
        for (int i = 1; i <= a; i++) {
            for (int k = 1; k <= a; k++) {
                // Stampa un asterisco se il valore di k è minore o uguale a i, altrimenti stampa un più
                if (k <= i) {
                    printf("*");
                } else {
                    printf("+");
                }
            }
            printf("\n"); // Vai alla riga successiva dopo aver completato una riga
        }
    }

    return 0;
}
