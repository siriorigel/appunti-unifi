#include <stdio.h>
#include <stdlib.h> // Per srand() e rand()
#include <math.h>
#include <time.h> // Per time()

// Funzione che richiede all'utente il numero di termini da utilizzare per la serie di Taylor
int chiediTermini() {
    int termini;
    printf("Inserisci il numero di termini per lo sviluppo in serie di Taylor: ");
    scanf("%d", &termini);
    return termini;
}

// Funzione che calcola lo sviluppo in serie di Taylor per log(1 + x) per n termini
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
    // Chiedere il numero di termini
    int termini = chiediTermini(); // Usa la funzione per ottenere il numero di termini

    // Verifica che il numero di termini sia valido
    if (termini <= 1) {
        printf("Errore: Il numero di termini deve essere maggiore di uno.\n");
        return 1;
    } else {
        printf("Numero di termini scelto: %d\n", termini);
    }

    // Inizializzare il generatore di numeri casuali
    srand(time(NULL));

    // Generare due numeri casuali tra 0 e 1
    double num1 = (double)rand() / RAND_MAX; // Rand ritorna un intero tra 0 e RAND_MAX
    double num2 = (double)rand() / RAND_MAX;

    // Calcolare lo sviluppo in serie di Taylor per entrambi i numeri
    double sviluppo1 = sviluppoLog(num1, termini);
    double sviluppo2 = sviluppoLog(num2, termini);

    // Calcolare i valori logaritmici attesi usando la funzione standard log()
    double valoreAtteso1 = log(1 + num1);
    double valoreAtteso2 = log(1 + num2);

    // Confronto tra i risultati
    printf("Primo numero casuale: %lf\n", num1);
    printf("Sviluppo in serie: %lf, Valore atteso: %lf\n", sviluppo1, valoreAtteso1);

    printf("Secondo numero casuale: %lf\n", num2);
    printf("Sviluppo in serie: %lf, Valore atteso: %lf\n", sviluppo2, valoreAtteso2);

    return 0; // Termina correttamente il programma
}
