/*------------------------------------------------------------------------------------------------------------------------------
Esercizio:
• Chiedere all'utente due estremi di un intervallo
• Generare 4 numeri casuali double in questo intervallo
• Calcolare la media tra i valori e valutare se risulta maggiore della media attesa attraverso un'espressione condizionale
--------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    double a, b, c; // Dichiarazione delle variabili per gli estremi dell'intervallo e l'ampiezza dell'intervallo
    double x, y, z, k; // Dichiarazione delle variabili per i numeri casuali generati
    double media, media_attesa; // Dichiarazione delle variabili per la media calcolata e la media attesa

    // Richiesta all'utente di inserire il primo estremo dell'intervallo
    printf("Primo estremo: \n");
    scanf("%lf", &a);

    // Richiesta all'utente di inserire il secondo estremo dell'intervallo
    printf("Secondo estremo: \n");
    scanf("%lf", &b);

    c = (b - a); // Calcolo dell'ampiezza dell'intervallo

    srand(time(NULL)); // Inizializzazione del generatore di numeri casuali utilizzando il tempo corrente come seme

    // Generazione di quattro numeri casuali all'interno dell'intervallo specificato
    x = ((double)rand() / (double)RAND_MAX) * c + a;
    y = ((double)rand() / (double)RAND_MAX) * c + a;
    z = ((double)rand() / (double)RAND_MAX) * c + a;
    k = ((double)rand() / (double)RAND_MAX) * c + a;

    // Calcolo della media dei numeri generati
    media = (x + y + z + k) / 4;

    // Calcolo della media attesa, che dovrebbe essere l'estremo inferiore dell'intervallo più la metà dell'ampiezza
    media_attesa = (c / 2) + a;

    // Stampa dei numeri generati, della media calcolata e della media attesa
    printf("I valori sono: %lf, %lf, %lf, %lf \n", x, y, z, k);
    printf("La media è %lf, mentre la media attesa è %lf \n", media, media_attesa);

    return 0; // Il programma termina con successo
}
