#include <stdio.h>
#include <math.h>

int main()
{
    // Dichiarazione delle variabili per l'accelerazione, il tempo e lo spazio
    float accelerazione; // Accelerazione in m/s^2
    float tempo;         // Tempo in secondi
    float spazio;        // Spazio percorso in metri

    /* Input da terminale */

    // Richiesta all'utente di inserire l'accelerazione
    printf("Inserisci l'accelerazione in m/s^2: \n");
    scanf("%f", &accelerazione);

    // Richiesta all'utente di inserire il tempo
    printf("Inserisci il tempo in secondi in s: \n");
    scanf("%f", &tempo);

    // Calcolo dello spazio percorso utilizzando la formula s = (1/2) * a * t^2
    spazio = 0.5 * accelerazione * pow(tempo, 2);

    // Stampa dello spazio percorso
    printf("Lo spazio percorso dopo %.2f s, all'accelerazione %.2f m/s^2, è di: %.2f m\n", tempo, accelerazione, spazio);

    // Il programma termina con successo
    return 0;
}
