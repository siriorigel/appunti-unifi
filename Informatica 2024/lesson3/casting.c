#include <stdio.h>
#include <math.h>

int main() {
    // Dichiarazione e inizializzazione delle variabili
    int i = 5;
    float f = 3.7;
    
    // Tentativo di sommare un intero e un float
    int iSomma = i + f;   // Questa operazione genera un errore
    
    // Tentativo di sommare un intero e un float
    float fSomma = i + f; // Questa operazione genera un errore
    
    // Stampa dei risultati
    printf("La somma intera di %d e %f è %d \n", i, f, iSomma); // Stampa l'errore generato
    printf("Conversione esplicita a float: %f\n", (float)iSomma); // Conversione esplicita dell'intero in float
    printf("La somma float di %d e %f è %f\n", i, f, fSomma); // Stampa l'errore generato

    return 0; // Il programma termina con successo
}
