#include <stdio.h>
#include <math.h>

// Dichiarazione della funzione per trovare il massimo tra tre numeri
float massimo(float, float, float);

int main() {
    float a, b, c;

    // Input di tre numeri
    printf("Digita tre numeri: \n");
    scanf("%f %f %f", &a, &b, &c);

    // Trova e stampa il massimo tra i tre numeri
    printf("Il massimo è %f \n", massimo(a, b, c));

    return 0;
}

// Definizione della funzione per trovare il massimo tra tre numeri
float massimo(float x, float y, float z) {
    float max = x;  // Assume che il primo numero sia il massimo

    // Controlla se il secondo numero è maggiore del massimo attuale
    if (y > max) 
        max = y;

    // Controlla se il terzo numero è maggiore del massimo attuale
    if (z > max) 
        max = z;

    return max;  // Restituisce il massimo tra i tre numeri
}
