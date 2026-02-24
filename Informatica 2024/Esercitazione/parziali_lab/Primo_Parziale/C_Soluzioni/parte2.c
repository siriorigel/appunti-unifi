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
    // Genera un numero casuale tra 0 e 2 * ampiezzaPasso
    double passo = ((double)rand() / RAND_MAX) * (2 * ampiezzaPasso);
    // Trasformalo in modo che sia nell'intervallo [-ampiezzaPasso, ampiezzaPasso]
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
        // Genera e stampa 10 passi casuali
        for (int i = 0; i < 10; i++) {
            double passo = genera_passo(ampiezzaPasso);
            printf("Passo %d: %lf\n", i + 1, passo);
        }
    }

    return 0;
}
