#include <stdio.h>
#include <stdlib.h>

// Funzione che richiede l'input dell'utente e verifica la validità dei valori
void richiedi_input(int *L, int *N) {
    // Ciclo per verificare che L sia un numero dispari maggiore di 5 e minore o uguale a 11
    do {
        printf("Inserisci la lunghezza del segmento (L) (numero dispari, maggiore di 5 e minore o uguale a 11): ");
        scanf("%d", L);
        if (*L % 2 == 0 || *L <= 5 || *L > 11) {
            printf("Errore: L deve essere un numero dispari maggiore di 5 e minore o uguale a 11.\n");
        }
    } while (*L % 2 == 0 || *L <= 5 || *L > 11);

    // Ciclo per verificare che N sia almeno 100
    do {
        printf("Inserisci il numero di replicazioni (N) (N deve essere almeno 100): ");
        scanf("%d", N);
        if (*N < 100) {
            printf("Errore: N deve essere almeno 100.\n");
        }
    } while (*N < 100);
}

int main() {
    int L, N;

    // Richiesta input per L e N
    richiedi_input(&L, &N);

    // Allocazione dinamica di un array lungo N per salvare i risultati delle simulazioni
    int *iterazioni = (int *)malloc(N * sizeof(int));
    if (iterazioni == NULL) {
        printf("Errore: memoria insufficiente per allocare l'array.\n");
        return 1;  // Termina il programma in caso di errore di allocazione
    }

    // Stampa per verificare che i valori siano corretti
    printf("Segmento di lunghezza L = %d, Numero di replicazioni N = %d\n", L, N);

    // Libera la memoria allocata dinamicamente
    free(iterazioni);

    return 0;
}
