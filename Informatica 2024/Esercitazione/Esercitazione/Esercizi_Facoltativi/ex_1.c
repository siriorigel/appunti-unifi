#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define L 100  // Limite del numero massimo di intervalli

void grafico(){
    // Apri Gnuplot
    FILE *gnuplot = popen("gnuplot -persist", "w");
    if (gnuplot == NULL) {
        perror("Errore nell'apertura di Gnuplot");
    }

    // Configurazioni Gnuplot
    fprintf(gnuplot, "set datafile separator ','\n");
    fprintf(gnuplot, "set terminal pngcairo\n");
    fprintf(gnuplot, "set output 'grafico.png'\n");
    fprintf(gnuplot, "set xlabel 'Tempo (s)'\n");
    fprintf(gnuplot, "set ylabel 'Posizione (m)'\n");

    // Comando per disegnare il grafico usando il file CSV
    fprintf(gnuplot, "plot 'dati.csv' using 1:2 with linespoints title 'Posizione nel tempo'\n");

    // Chiudi Gnuplot
    pclose(gnuplot);

    printf("Il grafico è stato creato e salvato come 'grafico.png'.\n");
}

int main() {
    float k, m, omega, T, dt, s_0, v_0;
    int N;

    // Controlli di input per k e m
    do {
        printf("Inserisci la costante elastica (k): ");
        scanf("%f", &k);
        if (k <= 0) {
            printf("La costante elastica deve essere positiva.\n");
        }
    } while (k <= 0);

    do {
        printf("Inserisci la massa (m): ");
        scanf("%f", &m);
        if (m <= 0) {
            printf("La massa deve essere positiva.\n");
        }
    } while (m <= 0);

    // Calcolo della frequenza angolare e del periodo
    omega = sqrt(k / m);
    T = 2 * M_PI / omega;
    printf("Periodo (T): %.2f secondi\n", T);

    // Controlli per il numero di intervalli
    do {
        printf("Inserisci il numero di intervalli di tempo: ");
        scanf("%d", &N);
        if (N <= 0 || N > L) {
            printf("Il numero di intervalli deve essere positivo e non superare %d.\n", L);
        }
    } while (N <= 0 || N > L);

    // Condizioni iniziali
    printf("Inserisci la velocità iniziale (v_0): ");
    scanf("%f", &v_0);

    printf("Inserisci lo spostamento iniziale (s_0): ");
    scanf("%f", &s_0);

    dt = T / N;

    // Apertura del file CSV
    FILE *csv_file = fopen("dati.csv", "w");
    if (csv_file == NULL) {
        perror("Errore nell'apertura del file");
        return 1;
    }

    // Scrittura delle intestazioni nel file CSV
    fprintf(csv_file, "Tempo(s),Posizione(m),Velocità(m/s)\n");

    // Calcolo e scrittura delle posizioni e velocità nel file CSV
    for (int i = 0; i <= N; i++) {
        float t = i * dt;
        fprintf(csv_file, "%.2f,%.2f,%.2f\n", t, s_0 * cos(omega * t) + (v_0 / omega) * sin(omega * t), -s_0 * omega * sin(omega * t) + v_0 * cos(omega * t));
    }

    fclose(csv_file);

    printf("Dati salvati in 'dati.csv'.\n");

    grafico();

    return 0;
}
