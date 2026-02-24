#include <stdio.h>
#include <math.h>

int main() {
    int n; // Dichiarazione della variabile per memorizzare il numero inserito dall'utente

    // Richiesta all'utente di inserire il numero da valutare
    printf("Inserisci il numero da valutare: \n");
    scanf("%d", &n);

    // Verifica se il numero è pari
    if (n % 2 == 0) {
        printf("Il numero è pari \n");
    } 
    // Se il numero è dispari
    else {
        printf("Il numero è dispari \n");

        // Verifica se il numero è divisibile per 5
        if (n % 5 == 0) {
            printf("Il numero è divisibile per 5 \n");
        } 
        // Se il numero non è divisibile per 5
        else {
            printf("Il numero non è divisibile per 5 \n");
        }
    }

    return 0; // Il programma termina con successo
}
