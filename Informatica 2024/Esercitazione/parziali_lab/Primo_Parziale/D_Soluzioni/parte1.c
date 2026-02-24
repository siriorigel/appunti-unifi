#include <stdio.h>

// Funzione che richiede all'utente il numero di termini da utilizzare per la serie di Taylor
int chiediTermini() {
    int termini;
    printf("Inserisci il numero di termini per lo sviluppo in serie di Taylor: ");
    scanf("%d", &termini);
    return termini;
}

int main() {
    int termini = chiediTermini(); // Usa la funzione per ottenere il numero di termini

    if (termini <= 1) {
        printf("Errore: Il numero di termini deve essere maggiore di uno.\n");
    } else {
        printf("Numero di termini scelto: %d\n", termini);
    }

    return 0; // Termina correttamente il programma
}
