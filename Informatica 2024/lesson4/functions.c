#include <stdio.h>
#include <math.h>

// Dichiarazione della funzione per calcolare l'area del cerchio
double calcola_area_cerchio(float);

int main() {
    float raggio, area;

    // Input del raggio del cerchio
    printf("Inserisci il raggio del cerchio: \n");
    scanf("%f", &raggio);

    // Calcola l'area del cerchio usando la funzione e memorizzala in 'area'
    area = calcola_area_cerchio(raggio);

    // Stampa il risultato
    printf("L'area del cerchio di raggio %.2f è: %.f \n", raggio, area);

    return 0;
}

// Definizione della funzione per calcolare l'area del cerchio
double calcola_area_cerchio(float r) {
    // Messaggio di notifica che la funzione è stata chiamata
    printf("Stai usando la funzione area_cerchio :) \n");

    // Calcola e restituisce l'area del cerchio usando la formula A = π * r^2
    return pow(r, 2) * M_PI;
}
