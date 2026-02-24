#include <stdio.h>

int main() {
    // Dichiarazione delle variabili per il numero di bit dei due numeri binari
    int N, M;

    // Richiesta all'utente di inserire il numero di bit del primo numero binario
    printf("Inserisci il numero di bit del primo numero binario: ");
    scanf("%d", &N);

    // Controllo se il numero di bit è positivo
    if (N <= 0) {
        printf("Errore: Inserire un numero di bit positivo.\n");
        return 1;
    }

    // Richiesta all'utente di inserire il numero di bit del secondo numero binario
    printf("Inserisci il numero di bit del secondo numero binario: ");
    scanf("%d", &M);

    // Controllo se il numero di bit è positivo
    if (M <= 0) {
        printf("Errore: Inserire un numero di bit positivo.\n");
        return 1;
    }

    int bit;

    // Inserimento del primo numero binario bit per bit
    printf("\nInserisci il primo numero binario bit per bit (da destra a sinistra):\n");
    for (int i = 0; i < N; i++) {
        printf("Bit %d: ", i + 1);
        scanf("%d", &bit);

        // Controllo se il bit inserito è valido (0 o 1)
        if (bit != 0 && bit != 1) {
            printf("Errore: Inserire solo 0 o 1.\n");
            return 1;
        }
    }

    // Inserimento del secondo numero binario bit per bit
    printf("\nInserisci il secondo numero binario bit per bit (da destra a sinistra):\n");
    for (int i = 0; i < M; i++) {
        printf("Bit %d: ", i + 1);
        scanf("%d", &bit);

        // Controllo se il bit inserito è valido (0 o 1)
        if (bit != 0 && bit != 1) {
            printf("Errore: Inserire solo 0 o 1.\n");
            return 1;
        }
    }

    return 0;
}
