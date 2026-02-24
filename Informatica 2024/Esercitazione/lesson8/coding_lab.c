/*---------------------------------------------------------------------------------------------------------------------
Moto del razzo

Questo programma simula il moto di un razzo, modellando la perdita di massa dovuta all'espulsione del gas e calcolando 
la velocità in funzione del tempo. Utilizza le equazioni della dinamica del razzo per determinare come la massa e la velocità 
cambiano nel tempo.

L'utente inserisce i parametri iniziali: la massa iniziale del razzo, il tasso di espulsione del gas (kg/s), e la velocità 
di espulsione del gas. Il programma chiede anche il numero di punti e il tempo di integrazione per eseguire i calcoli.

Il programma genera un vettore di tempo, calcola la massa e la velocità corrispondente per ogni intervallo di tempo, 
e utilizza un metodo di riduzione del passo temporale basato sulla derivata della velocità per migliorare la precisione 
del calcolo.

Alla fine, i dati vengono salvati su file e visualizzati utilizzando Gnuplot, generando grafici della massa e della velocità 
in funzione del tempo, oltre a un grafico per la variazione del passo temporale (dt).
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

void Chiedi_parametri(double* massa_iniziale, double* tasso_iniziale, double* velocità_espulzione) {
    do
    {
        printf("Inserisci la massa iniziale [kg]\n");
        scanf("%lf", massa_iniziale); 

        if (massa_iniziale<=0)
        {
            printf("Errore! Inserire una massa inizia positiva\n");
        }
        
    } while (*massa_iniziale <= 0);
    
    do
    {
        printf("Inserisci il tasso di espulsione del gas [kg/s]\n");
        scanf("%lf", tasso_iniziale); 

        if (tasso_iniziale<=0)
        {
            printf("Errore! Inserire un tasso positivo\n");
        }
        
    } while (*tasso_iniziale <= 0);
    
    do
    {
        printf("Inserisci la velocità di espulsione del gas [kg/s]\n");
        scanf("%lf", velocità_espulzione); 

        if (velocità_espulzione<=0)
        {
            printf("Errore! Inserire la velocità di espulsione positiva\n");
        }
        
    } while (*velocità_espulzione <= 0);
}

void tempo_massimo(double* t0, double massa_iniziale, double tasso_iniziale){
    *t0= massa_iniziale/ tasso_iniziale;
    printf("Il tempo massimo è %lf [s]\n", *t0);
}

double Chiedi_t_integrazione(double t0){
    double tempo_proposto;

    do
    {
        printf("Inserisci il tempo di integrazione [s]: ");
        scanf("%lf", &tempo_proposto);

        if (tempo_proposto<=0)
        {
            printf("Inserisci un tempo maggiore di 0 s\n");
        } else if (tempo_proposto>t0)
        {
            printf("Inserisci un tempo minore del tempo massimo\n");
        }
        
        

    } while (tempo_proposto<=0 || tempo_proposto > t0); 
    
    return tempo_proposto;
}

void genera_vettore_base(double* p, double t, double n){
    for (int i = 0; i < n; i++) {
        p[i] = (t/n) *i; 
    }
}

double massa(double massa_iniziale, double tasso_iniziale, double intervallo_tempo){
    double massa;

    massa = massa_iniziale - tasso_iniziale * intervallo_tempo;

    return massa;
}

double velocità(double massa_iniziale, double tasso_iniziale, double massa){
    double velocità;

    velocità = -tasso_iniziale*log((massa/ massa_iniziale));

    return velocità;
}

void riempi_vettori(double* m, double* v, double m0, double m_dot, double* t, int n){
        for (int i = 0; i < n; i++)
    {
        m[i]= massa(m0,m_dot,t[i]);
        v[i]= velocità(m0,m_dot,m[i]);
    }

}

double derivata_velocità(double m_dot, double m0, double tasso_iniziale, double* t){
    return (m_dot * tasso_iniziale)/(m0 - m_dot* *t);
}

void riduzione_DT(double m_dot, double m0, double tasso_iniziale, double* t, int n, double* v){
    double epsilon, dt;
    epsilon = 0.1234;

    for (int i = 0; i < n; i++)
    { 
        dt = epsilon / (v[i+1]-v[i]);
        t[i+1] = t[i]+ dt;
    }
}

void writeDataToFile(const char *filename, double* x, double* y, double* z, int size) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Errore nell'apertura del file");
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < size; i++) {
        fprintf(file, "%lf %lf %lf\n", x[i], y[i], z[i]);
    }
    
    fclose(file);
}

void writeDataToFile_DT(const char *filename, double* x, double* y, int size) {
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

void plotWithGnuplot_mass(const char *datafile, const char *outputfile) {
    FILE *gnuplot = popen("gnuplot -persist", "w");
    if (gnuplot == NULL) {
        perror("Errore nell'apertura di Gnuplot");
        exit(EXIT_FAILURE);
    }
    
    fprintf(gnuplot, "set terminal pngcairo\n"); // Output in formato PNG
    fprintf(gnuplot, "set output '%s'\n", outputfile); // File di output
    fprintf(gnuplot, "plot '%s' using 1:2 with linespoints title 'funzione m(t)'\n", datafile); // Comando per tracciare il grafico 

    pclose(gnuplot);
}

void plotWithGnuplot_velocity(const char *datafile, const char *outputfile) {
    FILE *gnuplot = popen("gnuplot -persist", "w");
    if (gnuplot == NULL) {
        perror("Errore nell'apertura di Gnuplot");
        exit(EXIT_FAILURE);
    }
    
    fprintf(gnuplot, "set terminal pngcairo\n"); // Output in formato PNG
    fprintf(gnuplot, "set output '%s'\n", outputfile); // File di output
    fprintf(gnuplot, "plot '%s' using 1:3 with linespoints title 'funzione v(t)'\n", datafile); // Comando per tracciare il grafico 

    pclose(gnuplot);
}

int main(){
    int n;
    double m_dot, m0, w, t0, tp, deriviata;

    Chiedi_parametri(&m0, &m_dot, &w);

    tempo_massimo(&t0, m0, m_dot);

    tp = Chiedi_t_integrazione(t0);

    Chiedi_numero_punti(&n);

    double* t = (double*)calloc(n, sizeof(double)); 
    if (t == NULL) {
        printf("Errore: impossibile allocare memoria.\n");
        return EXIT_FAILURE; 
    }

    double* m = (double*)calloc(n, sizeof(double)); 
    if (m == NULL) {
        printf("Errore: impossibile allocare memoria.\n");
        return EXIT_FAILURE; 
    }

    double* v = (double*)calloc(n, sizeof(double)); 
    if (v == NULL) {
        printf("Errore: impossibile allocare memoria.\n");
        return EXIT_FAILURE; 
    }

    genera_vettore_base(t, tp, n);

    riempi_vettori(m,v,m0,m_dot,t,n);

    riduzione_DT(m_dot, m0, w, t,n, v);

    double dt[n];

    for (int i = 0; i < n; i++)
    {
        dt[i] = 0.1234 / (v[i+1]-v[i]);
    }
    

    const char *datafile = "data.dat"; // File con i dati
    char *outputfile = "grafico-massa.png"; // Nome del file di output del grafico

    writeDataToFile(datafile, t, m, v, n);
    plotWithGnuplot_mass(datafile, outputfile);

    char *velocityfile = "grafico-velocità.png";
    plotWithGnuplot_velocity(datafile, velocityfile);

    char *dat = "grafico-dt.png";
    const char *datafile2 = "dt.dat"; // File con i dati
    writeDataToFile_DT(datafile2, t, dt, n);
    plotWithGnuplot_mass(datafile2, dat);

    free(v);
    free(m);

}