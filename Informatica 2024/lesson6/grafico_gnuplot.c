#include <stdio.h>
#include <stdlib.h>

void writeDataToFile(const char *filename, double x[], double y[], int size) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Errore nell'apertura del file");
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < size; i++) {
        fprintf(file, "%lf %lf\n", x[i], y[i]);
    }
    
    fclose(file);
}

void plotWithGnuplot(const char *datafile, const char *outputfile) {
    FILE *gnuplot = popen("gnuplot -persist", "w");
    if (gnuplot == NULL) {
        perror("Errore nell'apertura di Gnuplot");
        exit(EXIT_FAILURE);
    }
    
    fprintf(gnuplot, "set terminal pngcairo\n"); // Output in formato PNG
    fprintf(gnuplot, "set output '%s'\n", outputfile); // File di output
    fprintf(gnuplot, "plot '%s' using 1:2 with linespoints title 'Esempio di Grafico'\n", datafile); // Comando per tracciare il grafico
    pclose(gnuplot);
}

int main() {
    double x[] = {1.0, 2.0, 3.0, 4.0, 5.0}; // Esempio dati per l'asse x
    double y[] = {2.0, 3.0, 5.0, 7.0, 11.0}; // Esempio dati per l'asse y
    int size = sizeof(x) / sizeof(x[0]); // Numero di elementi nei array
    
    const char *datafile = "data.txt"; // File con i dati
    const char *outputfile = "grafico.png"; // Nome del file di output del grafico
    
    // Scrivi i dati su un file
    writeDataToFile(datafile, x, y, size);
    
    // Traccia il grafico con Gnuplot
    plotWithGnuplot(datafile, outputfile);
    
    printf("Grafico creato e salvato come %s\n", outputfile);
    
    return 0;
}
