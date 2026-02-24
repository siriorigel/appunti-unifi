#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define N 3

int main() {
    double array[N];  // Dichiarazione dell'array
    double max;       // Variabile per memorizzare il valore massimo
    int indice;       // Variabile per memorizzare l'indice del valore massimo

    // Input degli elementi dell'array
    for (int i = 0; i < N; i++) {
        printf("Inserisci un numero: \n");
        scanf("%lf", &array[i]);
    }
    
    // Trova il valore massimo nell'array e memorizza l'indice
    for (int i = 0; i < N; i++) {
        max = array[i];  // Supponiamo che il massimo sia l'elemento corrente
        if (array[i] < array[i + 1]) {  // Se l'elemento successivo è maggiore
            max = array[i + 1];         // Aggiorna il massimo
        } else {                        // Altrimenti
            indice = i;                 // Memorizza l'indice del massimo
        }
    }

    // Stampa il valore massimo e il suo indice
    printf("Il valore massimo è %lf e si trova all'indice %d \n", array[indice], indice);
    
    return 0;
}
