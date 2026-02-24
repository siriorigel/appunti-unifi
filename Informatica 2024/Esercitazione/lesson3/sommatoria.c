#include <stdio.h>
#include <math.h>

int main() {
    int i, n;            // Dichiarazione delle variabili per il contatore del ciclo e il numero di incrementi
    double x, x_0, dx, k; // Dichiarazione delle variabili per il risultato, il valore iniziale, l'incremento e la somma degli incrementi

    printf("Inserisci x_0: \n");
    scanf("%lf", &x_0); // Acquisizione del valore iniziale

    printf("Inserisci l'incremento dx:\n");
    scanf("%lf", &dx); // Acquisizione dell'incremento

    printf("Inserisci il numero di incrementi:\n");
    scanf("%d", &n); // Acquisizione del numero di incrementi

    k = 0; // Inizializzazione della variabile di somma degli incrementi

    // Calcolo della somma degli incrementi
    for (i = 1; i <= n; i++) {
        k += i * dx; // Ogni incremento è moltiplicato per il suo indice nel ciclo
    }

    x = x_0 + k; // Calcolo del risultato sommando il valore iniziale e la somma degli incrementi

    printf("Il risultato è %lf \n", x); // Stampa del risultato

    return 0; // Il programma termina con successo
}
