#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    const int MAX_SIZE = 100;  // Dimensione massima dell'array
    const float g = 9.81;  // Accelerazione di gravità in m/s^2
    int n;  // Numero di valori da inserire
    float tempi[MAX_SIZE];  // Array per i valori di tempo
    float distanze[MAX_SIZE];  // Array per le distanze calcolate

    // Chiedere all'utente quanti valori di tempo vuole inserire
    printf("Quanti valori di tempo vuoi inserire? ");
    scanf("%d", &n);

    if (n > MAX_SIZE) {
        printf("Il numero massimo di valori è %d. Usa un numero minore.\n", MAX_SIZE);
        return 1;  // Uscita con errore se il numero supera il limite
    }

    // Inserimento dei valori di tempo
    printf("Inserisci i valori di tempo (in secondi):\n");
    for (int i = 0; i < n; i++) {
        printf("Tempo %d: ", i + 1);
        scanf("%f", &tempi[i]);
    }

    // Calcolo delle distanze usando la formula della caduta libera
    for (int i = 0; i < n; i++) {
        distanze[i] = 0.5 * g * pow(tempi[i], 2);  // Distanza = 0.5 * g * (tempo^2)
    }

    // Apertura di un file CSV per scrivere i risultati
    FILE *file = fopen("risultati.csv", "w");  // Apre il file in modalità scrittura
    if (file == NULL) {
        printf("Errore nell'apertura del file.\n");
        return 1;  // Uscita con errore
    }

    // Scrittura dell'intestazione per le colonne
    fprintf(file, "Tempo (s),Distanza (m)\n");  // Separazione con virgola

    // Scrittura dei dati nel file CSV
    for (int i = 0; i < n; i++) {
        fprintf(file, "%.2f,%.2f\n", tempi[i], distanze[i]);  // Tempo e distanza separati da una virgola
    }

    fclose(file);  // Chiude il file

    printf("I risultati sono stati scritti nel file 'risultati.csv'.\n");  // Conferma all'utente

    // Utilizzo Gnuplot per disegnare il grafico
    FILE *gnuplot = popen("gnuplot -persist", "w");
    if (gnuplot == NULL) {
        perror("Errore nell'apertura di Gnuplot");
        return 1;
    }

    fprintf(gnuplot, "set datafile separator ','\n");  // I file CSV usano virgole
    fprintf(gnuplot, "set terminal pngcairo\n");  // Terminale per output PNG
    fprintf(gnuplot, "set output 'grafico.png'\n");  // File di output
    fprintf(gnuplot, "set xlabel 'Tempo (s)'\n");  // Etichetta asse x
    fprintf(gnuplot, "set ylabel 'Distanza (m)'\n");  // Etichetta asse y
    fprintf(gnuplot, "plot 'risultati.csv' using 1:2 with linespoints title 'Caduta libera'\n");  // Disegna il grafico
    pclose(gnuplot);

    printf("Il grafico è stato creato e salvato come 'grafico.png'.\n");

    return 0;  // Il programma termina correttamente
}
