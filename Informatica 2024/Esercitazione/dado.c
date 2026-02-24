#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Funzione per generare un numero casuale compreso tra 1 e 'a'
int Casual_number(int a) {
    return rand() % a + 1; // Utilizza l'operatore di modulo per ottenere un numero compreso tra 0 e 'a - 1', quindi aggiunge 1 per ottenere un numero tra 1 e 'a'
}

int main() {
    srand(time(NULL)); // Inizializza il generatore di numeri casuali con il seme basato sull'orologio di sistema

    int a, b, c;
    
    // Input del numero di lanci desiderati e del numero di facce del dado
    printf("Inserisci il numero di lanci che desideri fare: ");
    scanf("%d", &a);
    
    printf("Inserisci il numero di facce del dado: ");
    scanf("%d", &c);

    // Simula 'a' lanci del dado
    for (int i = 0; i < a; i++) {
        // Genera un numero casuale tra 1 e il numero di facce del dado
        b = Casual_number(c);
        
        // Stampa il risultato del lancio
        printf("Il numero tirato è: %d \n", b);
    }
    
    return 0;
}
