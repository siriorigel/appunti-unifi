#include <stdio.h>
#include <math.h>

// Dichiarazioni delle funzioni per le operazioni matematiche
float somma(float, float);
float sottrazione(float, float);
float moltiplicazione(float, float);
float divisione(float, float);
float percentage(float, float);

int main() {
    float a, b;
    char c;

    // Input dei due numeri
    printf("Inserisci il primo numero: \n");
    scanf("%f", &a);

    printf("Inserisci il secondo numero: \n");
    scanf("%f", &b);

    // Menu per la scelta dell'operazione
    do {
        printf("Inserisci l'operazione: \n +, Somma \n -, Differenza\n x, Moltiplicazione \n /, Divisione,  \n P, Percentuale \n");
        scanf(" %c", &c);

        // Selezione dell'operazione in base alla scelta dell'utente
        if (c == '+') {
            printf("Il risultato è: %f \n", somma(a, b));
        } else if (c == '-') {
            printf("Il risultato è: %f \n", sottrazione(a, b));
        } else if (c == 'x') {
            printf("Il risultato è: %f \n", moltiplicazione(a, b));
        } else if (c == '/') {
            printf("Il risultato è: %f \n", divisione(a, b));
        } else if (c == 'P') {
            printf("Il risultato è: %f \n", percentage(a, b));
        } else {
            printf(" \n Errore! Inserire una delle cinque operazioni richieste! \n \n");
        }
    } while (c != '+' && c != '-' && c != 'x' && c != '/' && c != 'P');

    return 0;
}

// Definizioni delle funzioni per le operazioni matematiche

float somma(float x, float y) {
    return x + y;
}

float sottrazione(float x, float y) {
    return x - y;
}

float moltiplicazione(float x, float y) {
    return x * y;
}

float divisione(float x, float y) {
    return x / y;
}

float percentage(float x, float y) {
    return (x / y) * 100;
}
