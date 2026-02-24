#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Funzione per generare un numero casuale compreso tra 'a' e 'b'
double generatore_numeri_casuali_intervallo(float a, float b) {
    double c = (b - a); // Calcola l'ampiezza dell'intervallo
    // Genera un numero casuale compreso tra 'a' e 'b'
    return ((double)rand() / (double)RAND_MAX) * c + a;
}

int main() {
    srand(time(NULL)); // Inizializza il generatore di numeri casuali con il seme basato sull'orologio di sistema
    
    double a, b, x, maxValue = -1.0; // Dichiarazione delle variabili
    int n;

    // Input dei valori 'a' e 'b'
    printf("Primo estremo: \n");
    scanf("%lf", &a);

    printf("Secondo estremo: \n");
    scanf("%lf", &b);

    // Input del numero di numeri casuali da generare
    printf("Quanti numeri casuali vuoi generare? \n");
    scanf("%d", &n);

    // Generazione dei numeri casuali e ricerca del massimo
    for (int i = 1; i <= n; i++) {
        // Genera un numero casuale nell'intervallo [a, b]
        x = generatore_numeri_casuali_intervallo(a, b);
        printf("%lf \n", x); // Stampa il numero casuale generato
        if (x > maxValue) {
            maxValue = x; // Aggiorna il massimo se necessario
        }
    }

    // Stampa del valore massimo generato
    printf("Il valore massimo generato è: %lf \n", maxValue);

    return 0;
}
