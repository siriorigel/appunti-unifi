#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Funzione che richiede l'input dell'utente e verifica la validità dei valori
void richiedi_input(int *L, int *N) {
    do {
        printf("Inserisci la lunghezza del segmento (L) (numero dispari, maggiore di 5 e minore o uguale a 11): ");
        scanf("%d", L);
        if (*L % 2 == 0 || *L <= 5 || *L > 11) {
            printf("Errore: L deve essere un numero dispari maggiore di 5 e minore o uguale a 11.\n");
        }
    } while (*L % 2 == 0 || *L <= 5 || *L > 11);

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
    int pos_formica1 = L / 2;
    int pos_formica2 = L / 2;
    int passi = 0;

    while (pos_formica1 > 0 && pos_formica1 < L - 1 && pos_formica2 > 0 && pos_formica2 < L - 1) {
        int movimento_formica1 = rand() % 3 - 1;
        int movimento_formica2 = rand() % 3 - 1;
        pos_formica1 += movimento_formica1;
        pos_formica2 += movimento_formica2;
        passi++;
    }
    return passi;
}

// Funzione che esegue N sfide e salva i risultati in un array dinamico
void ripeti_sfida(int L, int N, int *risultati) {
    for (int i = 0; i < N; i++) {
        risultati[i] = una_sfida(L);
    }
}

// Funzione che scrive i risultati delle sfide su un file
void scrivi_passi(int N, int *risultati) {
    FILE *file = fopen("passi.dat", "w");
    if (file == NULL) {
        printf("Errore nell'apertura del file passi.dat\n");
        return;
    }

    for (int i = 0; i < N; i++) {
        fprintf(file, "%d\n", risultati[i]);
    }

    fclose(file);
    printf("Risultati salvati nel file passi.dat\n");
}

// Funzione che esegue lo script Gnuplot per visualizzare i dati
void plotta_dati() {
    FILE *gnuplot = popen("gnuplot -persistent", "w");
    if (gnuplot == NULL) {
        printf("Errore nell'esecuzione di gnuplot\n");
        return;
    }

    // Script Gnuplot per visualizzare la distribuzione dei passi
    fprintf(gnuplot, "set title 'Distribuzione dei Passi Necessari'\n");
    fprintf(gnuplot, "set xlabel 'Numero di Passi'\n");
    fprintf(gnuplot, "set ylabel 'Frequenza'\n");
    fprintf(gnuplot, "bin_width = 1\n");
    fprintf(gnuplot, "bin(x, width) = width * floor(x / width)\n");
    fprintf(gnuplot, "plot 'passi.dat' using (bin($1, bin_width)):(1) smooth frequency with boxes title 'Passi'\n");
    fprintf(gnuplot, "pause mouse\n");

    pclose(gnuplot);
}

int main() {
    srand(time(NULL));

    int L, N;
    richiedi_input(&L, &N);

    // Allocazione dinamica per salvare i risultati delle sfide
    int *risultati = (int *)malloc(N * sizeof(int));
    if (risultati == NULL) {
        printf("Errore nell'allocazione della memoria.\n");
        return 1;
    }

    // Esegui le sfide e salva i risultati
    ripeti_sfida(L, N, risultati);

    // Scrivi i risultati nel file passi.dat
    scrivi_passi(N, risultati);

    // Esegui Gnuplot per visualizzare i dati
    plotta_dati();

    // Libera la memoria allocata
    free(risultati);

    return 0;
}
