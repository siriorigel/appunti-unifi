#include <stdio.h>
#include <math.h>

// Funzione che richiede all'utente il numero di termini da utilizzare per la serie di Taylor
int chiediTermini() {
    int termini;
    printf("Inserisci il numero di termini per lo sviluppo in serie di Taylor: ");
    scanf("%d", &termini);
    return termini;
}

double sviluppoLog(double x, int n) {
    double somma = 0.0; // Variabile per accumulare il risultato

    for (int i = 1; i <= n; i++) {
        // Calcola il termine corrente: x^i / i
        double termine = pow(x, i) / i;

        // Aggiungi o sottrai il termine a seconda del valore di i (dispari = aggiungi, pari = sottrai)
        if (i % 2 == 1) {
            somma += termine; // Aggiungi se i è dispari
        } else {
            somma -= termine; // Sottrai se i è pari
        }
    }

    return somma;
}

int main() {
    int termini = chiediTermini(); // Usa la funzione per ottenere il numero di termini

    if (termini <= 1) {
        printf("Errore: Il numero di termini deve essere maggiore di uno.\n");
    } else {
        printf("Numero di termini scelto: %d\n", termini);
    }

    double x =0.5; // Valore preso arbitrariamente per testare il programma

    double somma = sviluppoLog(x,termini);

    printf("Lo sviluppo in serie di taylor di log(1+x) centrato nel valore %lf e sviluppato con %d termini è %lf \n", x, termini, somma);

    return 0; // Termina correttamente il programma
}
