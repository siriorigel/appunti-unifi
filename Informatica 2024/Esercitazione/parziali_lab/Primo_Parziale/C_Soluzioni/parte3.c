#include <stdio.h>
#include <stdlib.h> // Per rand() e srand()
#include <time.h>  // Per time()

// Funzione per chiedere l'ampiezza del passo
double chiediAmpiezzaPasso() {
    double ampiezzaPasso;
    printf("Inserisci l'ampiezza massima del passo: ");
    scanf("%lf", &ampiezzaPasso);
    return ampiezzaPasso;
}

// Funzione che genera un passo casuale nell'intervallo [-ampiezzaPasso, ampiezzaPasso]
double genera_passo(double ampiezzaPasso) {
    double passo = ((double)rand() / RAND_MAX) * (2 * ampiezzaPasso);
    passo -= ampiezzaPasso;
    return passo;
}

int main() {
    // Inizializza il generatore di numeri casuali
    srand(time(NULL)); // Utilizza l'orario corrente come seed

    double ampiezzaPasso = chiediAmpiezzaPasso();

    if (ampiezzaPasso <= 0) {
        printf("Errore: l'ampiezza del passo deve essere maggiore di zero.\n");
    } else {
        double distanza = 0; // Distanza totale percorsa
        printf("Generando passi casuali...\n");

        // Genera e stampa 10 passi casuali, aggiornando la distanza
        for (int i = 0; i < 10; i++) {
            double passo = genera_passo(ampiezzaPasso);
            distanza += passo; // Aggiorna la distanza totale
            printf("Passo %d: %lf, Distanza totale: %lf\n", i + 1, passo, distanza);
        }

        // Dopo il ciclo, stampa la distanza finale dall'origine
        printf("Distanza finale dall'origine: %lf\n", distanza);

        // Controlla se la distanza totale è maggiore dell'ampiezza del passo
        if (distanza > ampiezzaPasso) {
            printf("L'utente si è mosso di una distanza maggiore rispetto all'ampiezza del passo.\n");
        } else {
            printf("L'utente si è mosso di una distanza minore o uguale rispetto all'ampiezza del passo.\n");
        }
    }

    return 0;
}
