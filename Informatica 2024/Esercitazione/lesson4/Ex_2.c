#include <stdio.h>
#include <math.h>

// Dichiarazioni delle funzioni per le operazioni matematiche
float somma(float, float);
float sottrazione(float, float);
float moltiplicazione(float, float);
float divisione(float, float);

int main() {
    float a, b;
    char c;

    // Input dei due numeri
    printf("Inserisci il primo numero: \n");
    scanf("%f", &a);

    printf("Inserisci il secondo numero: \n");
    scanf("%f", &b);

    // Input dell'operazione
    printf("Inserisci l'operazione: \n +, Somma \n -, Differenza\n x, Moltiplicazione \n /, Divisione  \n");
    scanf(" %c", &c);

    // Selezione dell'operazione e stampa del risultato
    if (c == '+') {
        printf("Il risultato è: %f \n", somma(a, b));
    } else if (c == '-') {
        printf("Il risultato è: %f \n", sottrazione(a, b));
    } else if (c == 'x') {
        printf("Il risultato è: %f \n", moltiplicazione(a, b));
    } else if (c == '/') {
        printf("Il risultato è: %f \n", divisione(a, b));
    } else {
        printf("Errore! Inserire una delle quattro operazioni richieste! \n");
    }

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
