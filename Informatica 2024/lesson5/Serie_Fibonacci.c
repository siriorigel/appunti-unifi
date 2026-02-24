#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n = 0, somma = 0;   // Variabili per il numero di termini e la somma
    long long numero = 0, a = 0, b = 1;  // Variabili per la successione di Fibonacci

    // Input del numero di termini desiderati
    printf("Inserisci il numero di termini richiesti: \n");
    scanf("%d", &n);

    printf("La successione è: 0");  // Stampa del primo termine della successione

    // Calcolo della successione di Fibonacci e della somma dei termini
    for (int i = 1; i < n; i++) {
        if (n > 2) {
            numero = a + b;  // Calcolo del termine successivo
            b = a;           // Aggiornamento del termine precedente
            a = numero;      // Aggiornamento del termine corrente
            printf("\t %lld", numero);  // Stampa del termine corrente
            somma += numero;  // Aggiornamento della somma
        } else if (n == 2) {
            printf("\t 1");   // Stampa del secondo termine se richiesto
            somma = 1;        // Assegnazione del valore della somma
        } else if (n == 1) {
            somma = 0;        // Se richiesto solo il primo termine, la somma è 0
        }
    }

    // Stampa del risultato della somma
    printf("\nLa somma dei termini della successione inserita è: %d \n", somma);
    
    return 0;
}
