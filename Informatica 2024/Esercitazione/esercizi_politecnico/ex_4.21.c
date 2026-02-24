/*----------------------------------------------------------------------------------------------------------------------------------------
4.21 Serie armonica
Il codice calcola la somma della serie armonica fino al termine n, dove n è un numero intero positivo inserito dall'utente. 
La serie armonica è definita come la somma dei reciproci degli interi positivi da 1 a n.
----------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    double somma = 0;

    // Richiesta all'utente di inserire un numero intero positivo diverso da zero
    printf("Inserisci un numero intero positivo e diverso da 0: ");
    // Controllo dell'input: se l'input non è un numero intero positivo, il programma termina
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Input non valido! Assicurati di inserire un numero intero positivo diverso da 0.\n");
        return 1;
    }

    // Calcolo della somma della serie armonica
    for (int i = 1; i <= n; i++) {
        somma += 1.0 / i;
    }

    // Stampare il risultato
    printf("La serie armonica fino a %d termini è: %.6f\n", n, somma);

    return 0;
}
