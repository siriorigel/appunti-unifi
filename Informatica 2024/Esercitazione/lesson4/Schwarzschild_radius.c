#include <stdio.h>
#include <math.h>

// Dichiarazione delle costanti
double G = 6.67430e-11;     // Costante di gravitazione universale
double c = 299792458;       // Velocità della luce nel vuoto
double M_sun = 1.98847e30;  // Massa del Sole in kg

// Dichiarazione delle funzioni
double Schwarzschild_radius(double);
double Conversione(double);

int main() {
    double M;
    char C;

    // Input della tipologia di massa desiderata
    printf("Seleziona la tipologia di masse che vuoi inserire.\n M - Masse Solari. \n K - Kilogrammi \n ");
    scanf("%c", &C);

    // Controllo e conversione della massa in base alla tipologia scelta
    if (C == 'M') {
        printf("Inserisci la tua massa in Masse solari: \n");
        scanf("%lf", &M);

        M = Conversione(M); // Conversione della massa da Masse solari a kg
    } else if (C == 'K') {
        printf("Inserisci la tua massa in Kilogrammi: \n");
        scanf("%lf", &M);
    }

    // Calcolo e stampa del raggio di Schwarzschild per la massa inserita
    printf("Il raggio di Scharzschild per la massa inserita è: %lf km \n", Schwarzschild_radius(M));

    return 0;
}

// Funzione per la conversione della massa da Masse solari a kg
double Conversione(double m) {
    m = m * M_sun; // Moltiplicazione per la massa del Sole
    return m;
}

// Funzione per il calcolo del raggio di Schwarzschild
double Schwarzschild_radius(double m) {
    double r;

    // Calcolo del raggio utilizzando la formula della relatività generale
    r = (2 * G * m) / pow(c, 2);

    // Conversione del raggio da metri a chilometri
    r = r / 1000;

    return r;
}
