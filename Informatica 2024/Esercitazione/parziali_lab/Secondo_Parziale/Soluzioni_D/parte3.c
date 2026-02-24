#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FORMICHE 100

// Prototipo delle funzioni
void richiedi_input(int *L, int *N);
double calcola_centro_di_massa(int posizioni[], int num_formiche);
int simula_diffusione(int L);
void ripeti_simulazione(int L, int N, int *risultati);
void scrivi_risultati(int *risultati, int N);
void plotta_dati();

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

// Funzione che richiede input per L e N
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

// Funzione che ripete la simulazione N volte e salva i risultati nell'array
void ripeti_simulazione(int L, int N, int *risultati) {
    for (int i = 0; i < N; i++) {
        risultati[i] = simula_diffusione(L);  // Esegue la simulazione e salva il numero di iterazioni
    }
}

// Funzione che scrive i risultati in un file iterazioni.dat
void scrivi_risultati(int *risultati, int N) {
    FILE *file = fopen("iterazioni.dat", "w");
    if (file == NULL) {
        printf("Errore nell'apertura del file!\n");
        exit(1);
    }

    for (int i = 0; i < N; i++) {
        fprintf(file, "%d\n", risultati[i]);
    }

    fclose(file);
}

// Funzione che esegue gnuplot per visualizzare i risultati
void plotta_dati() {
    FILE *gnuplot = popen("gnuplot -persistent", "w");
    if (gnuplot == NULL) {
        printf("Errore nell'esecuzione di gnuplot!\n");
        exit(1);
    }

    fprintf(gnuplot, "set title 'Distribuzione delle Iterazioni Necessarie'\n");
    fprintf(gnuplot, "set xlabel 'Numero di Iterazioni'\n");
    fprintf(gnuplot, "set ylabel 'Frequenza'\n");
    fprintf(gnuplot, "bin_width = 1\n");
    fprintf(gnuplot, "bin(x, width) = width * floor(x / width)\n");
    fprintf(gnuplot, "plot 'iterazioni.dat' using (bin($1, bin_width)):(1) smooth frequency with boxes title 'Iterazioni'\n");
    fprintf(gnuplot, "pause mouse\n");

    pclose(gnuplot);
}

int main() {
    int L, N;

    // Richiesta input per L e N
    richiedi_input(&L, &N);

    // Allocazione dinamica dell'array per salvare i risultati
    int *risultati = (int *)malloc(N * sizeof(int));
    if (risultati == NULL) {
        printf("Errore nell'allocazione della memoria!\n");
        return 1;
    }

    // Ripeti la simulazione N volte e salva i risultati
    ripeti_simulazione(L, N, risultati);

    // Salva i risultati in un file
    scrivi_risultati(risultati, N);

    // Esegui gnuplot per visualizzare i dati
    plotta_dati();

    // Libera la memoria allocata
    free(risultati);

    return 0;
}
