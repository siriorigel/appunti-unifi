/*-------------------------------------------------------------------------------------------------
Scrivere il codice capace di:
    1) chiedere una stringa in input
    2) chiedere un carattere in input
    3) Se la stringa contiene il carattere, stampare:
        'Il carattere è presente almeno una volta nella stringa’
        Altrimenti stampare:
        'Il carattere non è presente'
-------------------------------------------------------------------------------------------------*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N 100

int main() {
    char s[N], carattere;  // Dichiarazione delle variabili
    int i = 0, found = 0, indice = 0;  // Inizializzazione dei contatori e del flag

    printf("Inserisci una stringa: ");  // Input della stringa
    scanf("%s", s);

    printf("Inserisci un carattere che vuoi cercare all'interno della stringa: ");  // Input del carattere
    scanf(" %c", &carattere);

    unsigned int len = strlen(s);  // Calcolo della lunghezza della stringa

    // Scansione della stringa per cercare il carattere
    while (i < len) {
        if (s[i] == carattere) {  // Se il carattere è trovato, setta found a 1 e memorizza l'indice
            found = 1;
            indice = i;
            break;  // Esci dal ciclo perché hai trovato il carattere
        }
        i++;  // Passa al carattere successivo
    }

    // Stampa del risultato
    if (found == 1) {
        printf("Il carattere '%c' è presente almeno una volta nella stringa (indice %d)\n", carattere, indice);
    } else {
        printf("Il carattere '%c' non è presente nella stringa\n", carattere);
    }

    return 0;
}
