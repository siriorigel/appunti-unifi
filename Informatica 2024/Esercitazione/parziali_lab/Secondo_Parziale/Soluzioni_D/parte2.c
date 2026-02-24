#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FORMICHE 100

// Prototipo della funzione richiedi_input
void richiedi_input(int *L, int *N);

// Funzione che calcola il centro di massa delle formiche
double calcola_centro_di_massa(int posizioni[], int num_formiche) {
    int somma_posizioni = 0;
    for (int i = 0; i < num_formiche; i++) {
        somma_posizioni += posizioni[i];
    }
    return (double)somma_posizioni / num_formiche;
}

// Funzione che simula la diffusione delle formiche su un segmento di lunghezza L
int simula_diffusione(int L) {
    int posizioni[NUM_FORMICHE] = {0};  // Inizializza tutte le formiche alla posizione 0 (capo sinistro)
    int iterazioni = 0;
    double centro_di_massa;
    int metà_segmento = L / 2;

    // Genera numeri casuali
    srand(time(NULL));

    // Ciclo che simula la diffusione fino a quando il centro di massa è nell'intervallo desiderato
    do {
        iterazioni++;

        // Muove ciascuna formica
        for (int i = 0; i < NUM_FORMICHE; i++) {
            int passo = rand() % 3 - 1;  // Genera -1, 0 o 1 (sinistra, fermo, destra)
            posizioni[i] += passo;

            // Verifica che la formica rimanga nei limiti del segmento
            if (posizioni[i] < 0) {
                posizioni[i] = 0;
            } else if (posizioni[i] > L) {
                posizioni[i] = L;
            }
        }

        // Calcola il centro di massa
        centro_di_massa = calcola_centro_di_massa(posizioni, NUM_FORMICHE);

    } while (centro_di_massa < metà_segmento - 1 || centro_di_massa > metà_segmento + 1);

    // Restituisce il numero di iterazioni necessarie
    return iterazioni;
}

// Definizione della funzione richiedi_input
void richiedi_input(int *L, int *N) {
    do {
        printf("Inserisci la lunghezza del segmento L (dispari, > 5 e <= 11): ");
        scanf("%d", L);
    } while (*L <= 5 || *L > 11 || *L % 2 == 0);

    do {
        printf("Inserisci il numero di replicazioni N (almeno 100): ");
        scanf("%d", N);
    } while (*N < 100);
}

int main() {
    int L, N;

    // Richiesta input per L e N
    richiedi_input(&L, &N);

    // Esempio di chiamata alla funzione simula_diffusione
    int numero_iterazioni = simula_diffusione(L);

    printf("Il numero di iterazioni necessarie per raggiungere l'omogeneità è: %d\n", numero_iterazioni);

    return 0;
}
