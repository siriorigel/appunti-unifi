#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Definizione delle costanti
#define XV 10.0
#define DX 0.01
#define NE 1000

// Prototipi delle funzioni
int chiediNumeroMisure();
double simulaMisura();
void riempiVettoreMisure(double *misure, int n);
double calcolaMediaCampionaria(double *misure, int n);
double calcolaDeviazioneStandardCampionaria(double *misure, int n, double media);
void generaGaussiana(double media, double deviazioneStandard, const char* filename);

int main() {
    srand(time(NULL));

    int n = chiediNumeroMisure();
    double *misure = (double *)malloc(n * sizeof(double));

    if (misure == NULL) {
        printf("Errore nell'allocazione della memoria.\n");
        return 1;
    }

    riempiVettoreMisure(misure, n);

    double media = calcolaMediaCampionaria(misure, n);
    double deviazioneStandard = calcolaDeviazioneStandardCampionaria(misure, n, media);

    printf("Media campionaria: %.5f\n", media);
    printf("Deviazione standard campionaria: %.5f\n", deviazioneStandard);

    // Salva le misure in un file
    FILE *file = fopen("misure.dat", "w");
    if (file == NULL) {
        printf("Errore nell'apertura del file.\n");
        free(misure);
        return 1;
    }
    for (int i = 0; i < n; i++) {
        fprintf(file, "%.5f\n", misure[i]);
    }
    fclose(file);

    // Genera il file gauss.dat
    generaGaussiana(media, deviazioneStandard, "gauss.dat");

    free(misure);
    return 0;
}

// Funzione per chiedere il numero di misure da fare
int chiediNumeroMisure() {
    int n;
    printf("Inserisci il numero di misure da fare: ");
    scanf("%d", &n);
    return n;
}

// Funzione che simula una misura
double simulaMisura() {
    double misura = XV;
    for (int i = 0; i < NE; i++) {
        misura += (rand() / (double)RAND_MAX - 0.5) * 2 * DX;
    }
    return misura;
}

// Funzione per riempire il vettore delle misure
void riempiVettoreMisure(double *misure, int n) {
    for (int i = 0; i < n; i++) {
        misure[i] = simulaMisura();
    }
}

// Funzione per calcolare la media campionaria
double calcolaMediaCampionaria(double *misure, int n) {
    double somma = 0.0;
    for (int i = 0; i < n; i++) {
        somma += misure[i];
    }
    return somma / n;
}

// Funzione per calcolare la deviazione standard campionaria
double calcolaDeviazioneStandardCampionaria(double *misure, int n, double media) {
    double sommaQuadrati = 0.0;
    for (int i = 0; i < n; i++) {
        sommaQuadrati += pow(misure[i] - media, 2);
    }
    return sqrt(sommaQuadrati / (n - 1));
}

// Funzione per generare la distribuzione gaussiana e salvarla in un file
void generaGaussiana(double media, double deviazioneStandard, const char* filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Errore nell'apertura del file %s.\n", filename);
        return;
    }

    int numPoints = 100000;
    double x, y;
    double step = (6 * deviazioneStandard) / numPoints;
    for (int i = 0; i <= numPoints; i++) {
        x = media - 3 * deviazioneStandard + i * step;
        y = (1 / (deviazioneStandard * sqrt(2 * M_PI))) * exp(-0.5 * pow((x - media) / deviazioneStandard, 2));
        fprintf(file, "%.5f %.5f\n", x, y);
    }

    fclose(file);
}
