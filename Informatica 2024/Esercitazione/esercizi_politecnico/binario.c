#include <stdio.h>
#include <math.h>

int main() {
    int N;
    // Input del numero di bit del numero binario
    printf("Inserisci il numero di bit del numero binario: ");
    scanf("%d", &N);

    // Verifica se il numero di bit è positivo
    if (N <= 0) {
        printf("Errore: Inserire un numero di bit positivo.\n");
        return 1; // Termina il programma con codice di errore
    }

    int numeroDecimale = 0;
    int bit;

    // Input dei bit del numero binario
    printf("Inserisci il numero binario bit per bit (da destra a sinistra):\n");

    for (int i = 0; i < N; i++) {
        printf("Bit %d: ", i + 1);
        scanf("%d", &bit);

        // Verifica se il bit inserito è valido (0 o 1)
        if (bit != 0 && bit != 1) {
            printf("Errore: Inserire solo 0 o 1.\n");
            return 1; // Termina il programma con codice di errore
        }

        // Aggiorna il numero decimale in base al bit inserito
        numeroDecimale += bit * (int)pow(2, i);
    }

    // Stampa il numero decimale corrispondente
    printf("Il numero decimale corrispondente è: %d\n", numeroDecimale);

    return 0; // Termina il programma con successo
}
