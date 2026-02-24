#include <stdio.h>
#include <stdlib.h>

// Funzione per richiedere l'input dell'utente e controllare la validità dei dati
void richiedi_input(int *L, int *N) {
    // Ciclo che continua a richiedere il valore di L finché non è valido
    do {
        printf("Inserisci la lunghezza del segmento (L) (numero dispari, maggiore di 5 e minore o uguale a 11): ");
        scanf("%d", L);

        // Controlla se L è dispari, maggiore di 5 e minore o uguale a 11
        if (*L % 2 == 0 || *L <= 5 || *L > 11) {
            printf("Errore: L deve essere un numero dispari maggiore di 5 e minore o uguale a 11.\n");
        }
    } while (*L % 2 == 0 || *L <= 5 || *L > 11);  // Ripete finché la condizione non è soddisfatta

    // Ciclo che continua a richiedere il valore di N finché non è valido
    do {
        printf("Inserisci il numero di sfide (N) (N deve essere almeno 100): ");
        scanf("%d", N);

        // Controlla se N è almeno 100
        if (*N < 100) {
            printf("Errore: N deve essere almeno 100.\n");
        }
    } while (*N < 100);  // Ripete finché N non è almeno 100
}

int main() {
    int L, N;

    // Chiama la funzione richiedi_input per ottenere L e N dall'utente
    richiedi_input(&L, &N);

    // Allocazione dinamica dell'array per salvare i risultati delle sfide
    int *risultati = (int*) malloc(N * sizeof(int));

    if (risultati == NULL) {
        // Se l'allocazione fallisce, esce dal programma
        printf("Errore nell'allocazione della memoria.\n");
        return 1;
    }

    printf("L: %d\n", L);
    printf("N: %d\n", N);
    
    // Qui, l'array risultati è pronto per essere utilizzato per memorizzare i dati delle sfide
    // Nelle prossime parti del programma, potrai popolare l'array con i dati necessari

    // Libera la memoria allocata dinamicamente
    free(risultati);

    return 0;
}
