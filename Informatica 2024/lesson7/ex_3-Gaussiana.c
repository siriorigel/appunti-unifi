/*---------------------------------------------------------------------------------------------------------------------
Disegna una Gaussiana usando le funzioni
---------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Chiedi_numero_punti(int* n) {
    do {
        printf("Inserisci il numero di punti\n");
        scanf("%d", n); 
    } while (*n <= 0);
}

void Chiedi_parametri(double* media, double* sigma, int* Numero_Sigma) {
    do
    {
        printf("Inserisci la media\n");
        scanf("%lf", media); 
        printf("Inserisci sigma\n");
        scanf("%lf", sigma);
        printf("Inserisci il numero di sigma\n");
        scanf("%d", Numero_Sigma);  
    } while (*media <= 0 || *sigma <= 0 || *Numero_Sigma <=0);
    
}

double Gauss(double media, double sigma, double x){
    return (1.0 / (sigma * sqrt(2*M_PI)))*exp(-pow(x-media,2) / (2*pow(sigma,2)));
}

void genera_vettore(double* p, double Ns, double sigma, int n, double media){
    for (int i = 0; i < n; i++) {
        p[i] = media - Ns*sigma+i*(2*Ns*sigma/(n-1)); 
    }
}

void writeDataToFile(const char *filename, double* x, double* y, int size) {
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
    fprintf(gnuplot, "plot '%s' using 1:2 with linespoints title 'Gaussiana'\n", datafile); // Comando per tracciare il grafico
    pclose(gnuplot);
}


int main(){
    int n, Ns;
    double media, sigma;

    Chiedi_numero_punti(&n);
    Chiedi_parametri(&media, &sigma, &Ns);

    double intervallo = 2*Ns*sigma;

    double* x = (double*)calloc(n, sizeof(double)); 
    if (x == NULL) {
        printf("Errore: impossibile allocare memoria.\n");
        return EXIT_FAILURE; 
    }
    
    genera_vettore(x, Ns, sigma, n, media);

    double* y = (double*)calloc(n, sizeof(double)); 
    if (y == NULL) {
        printf("Errore: impossibile allocare memoria.\n");
        return EXIT_FAILURE; 
    }

    for (int i = 0; i < n; i++)
    {
        y[i]=Gauss(media, sigma, x[i]);
    }
    
    const char *datafile = "data.dat"; // File con i dati
    const char *outputfile = "grafico.png"; // Nome del file di output del grafico

    writeDataToFile(datafile, x, y, n);
    plotWithGnuplot(datafile, outputfile);

    free(x);
    free(y);

}