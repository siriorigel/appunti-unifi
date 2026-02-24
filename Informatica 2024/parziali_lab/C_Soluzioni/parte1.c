#include <stdio.h>

// Funzione per chiedere l'ampiezza del passo
double chiediAmpiezzaPasso() {
    double ampiezzaPasso;
    printf("Inserisci l'ampiezza massima del passo: ");
    scanf("%lf", &ampiezzaPasso);
    return ampiezzaPasso;
}

int main() {
    // Chiedi l'ampiezza del passo tramite la funzione dedicata
    double ampiezzaPasso = chiediAmpiezzaPasso();

    if (ampiezzaPasso <= 0) {
        printf("Errore: l'ampiezza del passo deve essere maggiore di zero.\n");
    } else {
        printf("L'ampiezza scelta è: %lf\n", ampiezzaPasso);
    }

    return 0;
}
