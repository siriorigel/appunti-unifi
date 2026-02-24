#include <stdio.h>

int main()
{
    // Dichiarazione delle variabili per la base, l'altezza, l'area del rettangolo e il numero di cifre significative
    float base;          // Lunghezza della base del rettangolo
    float altezza;       // Lunghezza dell'altezza del rettangolo
    float area;          // Area del rettangolo
    int numero_cs;       // Numero di cifre significative per la stampa dell'area

    /* Input da terminale */

    // Richiesta all'utente di inserire la base del rettangolo
    printf("Inserisci la base: \n");
    scanf("%f", &base);

    // Richiesta all'utente di inserire l'altezza del rettangolo
    printf("Inserisci l'altezza: \n");
    scanf("%f", &altezza);

    // Richiesta all'utente del numero di cifre significative desiderate
    printf("Quante cifre significative ti interessano? \n");
    scanf("%d", &numero_cs);

    // Calcolo dell'area del rettangolo utilizzando la formula Area = Base * Altezza
    area = base * altezza;

    // Stampa dell'area del rettangolo con un numero specificato di cifre significative
    printf("L'area del rettangolo con base %.3f e altezza %f è: %.*f m^2 \n \n", base, altezza, numero_cs, area);

    // Il programma termina con successo
    return 0;
}
