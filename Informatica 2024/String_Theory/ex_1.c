#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N 20

int main() {
    // Dichiarazione delle variabili
    char s[N];       // Array per memorizzare la stringa
    int c = 0, found = 0, k = 0;  // Variabili di conteggio e flag di trovato

    // Input della stringa
    printf("Inserisci una stringa di massimo 20 caratteri: \n");
    scanf("%s", s);

    unsigned int len = strlen(s);  // Lunghezza della stringa inserita

    // Scansione della stringa per cercare caratteri ripetuti
    while (c < len && found == 0) {
        k = c + 1;  // Inizia la scansione dal carattere successivo a c

        while (k < len && found == 0) {
            // Se viene trovato un carattere ripetuto, stampa e imposta found a 1
            if (s[c] == s[k]) {
                printf("Ecco il carattere ripetuto: %c \n", s[c]);
                found = 1;
            }
            k += 1;  // Passa al prossimo carattere nella stringa
        }
        c += 1;  // Passa al prossimo carattere nella stringa
    }

    // Se non è stato trovato alcun carattere ripetuto, stampa un messaggio
    if (found == 0) {
        printf("Not found! \n");
    }

    return 0;
}
