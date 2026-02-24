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
    
    double a, b, c, x; // Dichiarazione delle variabili
    int n, i = 1;

    // Input dei valori 'a' e 'b'
    printf("Primo estremo: \n");
    scanf("%lf", &a);

    printf("Secondo estremo: \n");
    scanf("%lf", &b);

    // Input del numero di numeri casuali da generare
    printf("Quanti numeri casuali vuoi generare? \n");
    scanf("%d", &n);

    // Generazione dei numeri casuali
    while (i <= n) {
        // Genera un numero casuale nell'intervallo [a, b]
        x = generatore_numeri_casuali_intervallo(a, b);
        // Stampa il numero casuale generato
        printf("%lf \n", x);
        
        // Aggiorna il massimo se necessario
        if (x > c) {
            c = x;
        }
        i++;
    }
    
    // Stampa del valore massimo generato
    printf("Il valore massimo generato è: %lf \n", c);

    return 0;
}
