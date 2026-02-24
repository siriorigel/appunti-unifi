#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Funzione che richiede l'input dell'utente e verifica la validità dei valori
void richiedi_input(int *L, int *N) {
    // Ciclo per assicurarsi che L sia un numero dispari maggiore di 5 e minore o uguale a 11
    do {
        printf("Inserisci la lunghezza del segmento (L) (numero dispari, maggiore di 5 e minore o uguale a 11): ");
        scanf("%d", L);

        if (*L % 2 == 0 || *L <= 5 || *L > 11) {
            printf("Errore: L deve essere un numero dispari maggiore di 5 e minore o uguale a 11.\n");
        }
    } while (*L % 2 == 0 || *L <= 5 || *L > 11);

    // Ciclo per assicurarsi che N sia almeno 100
    do {
        printf("Inserisci il numero di sfide (N) (N deve essere almeno 100): ");
        scanf("%d", N);

        if (*N < 100) {
            printf("Errore: N deve essere almeno 100.\n");
        }
    } while (*N < 100);
}

// Funzione che simula una singola sfida tra due formiche
int una_sfida(int L) {
    // Posizionare entrambe le formiche al centro del segmento
    int pos_formica1 = L / 2;
    int pos_formica2 = L / 2;

    int passi = 0;  // Conta i passi effettuati durante la sfida

    printf("Posizione iniziale formica 1: %d, Posizione iniziale formica 2: %d\n", pos_formica1, pos_formica2);

    // Ciclo che continua finché una formica non raggiunge uno dei capi del segmento
    while (pos_formica1 > 0 && pos_formica1 < L - 1 && pos_formica2 > 0 && pos_formica2 < L - 1) {
        // Movimento casuale delle formiche (-1: sinistra, 0: fermo, 1: destra)
        int movimento_formica1 = rand() % 3 - 1;  // Numeri casuali tra -1, 0 e 1
        int movimento_formica2 = rand() % 3 - 1;  // Numeri casuali tra -1, 0 e 1

        // Aggiorna la posizione delle formiche
        pos_formica1 += movimento_formica1;
        pos_formica2 += movimento_formica2;

        passi++;  // Incrementa il contatore dei passi

        // Stampa la posizione attuale delle formiche
        printf("Passo %d: Posizione formica 1: %d, Posizione formica 2: %d\n", passi, pos_formica1, pos_formica2);
    }

    // Quando una formica raggiunge un capo del segmento, il ciclo termina
    printf("Una formica ha vinto in %d passi.\n", passi);

    return passi;  // Restituisce il numero di passi necessari per concludere la sfida
}

int main() {
    // Inizializza il generatore di numeri casuali
    srand(time(NULL));

    int L, N;

    // Richiede l'input dell'utente per L e N
    richiedi_input(&L, &N);

    // Allocazione dinamica di un array per salvare i risultati delle sfide
    int *risultati = (int *)malloc(N * sizeof(int));

    // Controllo per verificare che l'allocazione della memoria sia riuscita
    if (risultati == NULL) {
        printf("Errore nell'allocazione della memoria.\n");
        return 1;  // Esce dal programma in caso di errore
    }

    // Esegue N sfide e memorizza i risultati nell'array
    for (int i = 0; i < N; i++) {
        printf("Inizio della sfida %d:\n", i + 1);
        risultati[i] = una_sfida(L);
    }

    // (Opzionale) Stampa i risultati di tutte le sfide
    printf("\nRisultati delle sfide:\n");
    for (int i = 0; i < N; i++) {
        printf("Sfida %d: %d passi\n", i + 1, risultati[i]);
    }

    // Libera la memoria allocata dinamicamente
    free(risultati);

    return 0;
}
