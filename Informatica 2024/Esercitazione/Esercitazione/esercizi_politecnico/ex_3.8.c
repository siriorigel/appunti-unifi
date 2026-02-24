#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int mese;

    // Acquisizione del numero del mese
    printf("Inserisci un numero tra 1 e 12: ");
    scanf("%d", &mese);

    // Verifica il numero del mese e stampa il nome corrispondente
    if (mese == 1) {
        printf("Gennaio\n");
    } else if (mese == 2) {
        printf("Febbraio\n");
    } else if (mese == 3) {
        printf("Marzo\n");
    } else if (mese == 4) {
        printf("Aprile\n");
    } else if (mese == 5) {
        printf("Maggio\n");
    } else if (mese == 6) {
        printf("Giugno\n");
    } else if (mese == 7) {
        printf("Luglio\n");
    } else if (mese == 8) {
        printf("Agosto\n");
    } else if (mese == 9) {
        printf("Settembre\n");
    } else if (mese == 10) {
        printf("Ottobre\n");
    } else if (mese == 11) {
        printf("Novembre\n");
    } else if (mese == 12) {
        printf("Dicembre\n");
    } else {
        // Se il numero del mese non è compreso tra 1 e 12, stampare un messaggio di errore
        printf("Numero di mese non valido. Assicurati di inserire un numero tra 1 e 12.\n");
    }

    return 0;
}
