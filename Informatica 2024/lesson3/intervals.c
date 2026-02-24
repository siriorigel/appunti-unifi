#include <stdio.h>
#include <math.h>

int main() {
    int n; // Dichiarazione della variabile per memorizzare il numero inserito dall'utente

    // Richiesta all'utente di inserire il numero da valutare
    printf("Inserisci il numero da valutare: \n");
    scanf("%d", &n);

    // Verifica se il numero è maggiore di 100
    if (n > 100) {
        printf("Il numero è maggiore di 100 \n");
    } 
    // Verifica se il numero è compreso tra 51 e 100 inclusi
    else if (n <= 100 && n > 50) {
        printf("Il numero è minore o uguale a 100 e maggiore di 50 \n");
    } 
    // Verifica se il numero è esattamente 50
    else if (n == 50) {
        printf("Il numero è esattamente 50 \n");
    } 
    // Verifica se il numero è compreso tra 11 e 50 inclusi
    else if (n <= 50 && n > 10) {
        printf("Il numero è minore o uguale a 50 e maggiore di 10 \n");
    } 
    // Se non si verifica nessuna delle condizioni precedenti, il numero deve essere minore o uguale a 10
    else if (n <= 10) {
        printf("Il numero è minore o uguale a 10 \n");
    }

    return 0; // Il programma termina con successo
}
