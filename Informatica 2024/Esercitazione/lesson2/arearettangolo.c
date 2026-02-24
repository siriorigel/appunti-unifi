#include <stdio.h>

int main()
{
    // Dichiarazione delle variabili per la base, l'altezza e l'area del rettangolo
    float base;      // Lunghezza della base del rettangolo
    float altezza;   // Lunghezza dell'altezza del rettangolo
    float area;      // Area del rettangolo

    // Assegnazione dei valori per la base e l'altezza del rettangolo
    base = 2;                  // Base del rettangolo
    altezza = 0.0000006;       // Altezza del rettangolo

    // Calcolo dell'area del rettangolo utilizzando la formula Area = Base * Altezza
    area = base * altezza;

    // Stampa dell'area del rettangolo utilizzando la notazione scientifica con 4 cifre decimali
    printf("L'area del rettangolo con base %.0f e altezza %f è: %.4e m^2 \n \n", base, altezza, area);
    
    // Il programma termina con successo
    return 0;
}
