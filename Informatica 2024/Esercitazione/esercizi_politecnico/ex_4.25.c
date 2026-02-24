/*----------------------------------------------------------------------------------------------------------------------------------------
4.25 Triangolo di Floyd
----------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, c = 1;

    // Input del numero di righe da stampare
    printf("Inserisci il numero di righe che vuoi stampare: ");
    scanf("%d", &n);

    // Loop per ogni riga
    for (int i = 1; i <= n; i++) {
        // Loop per ogni numero nella riga
        for (int j = 1; j <= i; j++) {
            // Stampa il valore corrente di c e incrementa c
            printf("%d ", c);
            c++;
        }
        // Vai alla riga successiva dopo aver stampato la riga corrente
        printf("\n");
    }

    return 0; // Esco dal programma con successo
}
