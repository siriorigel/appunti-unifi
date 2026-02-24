#include <stdio.h>

// Definizione della costante per pi greco
#define pigreco 3.141592654

int main()
{
    // Dichiarazione delle variabili per il raggio e l'area del cerchio
    float r;            // Raggio del cerchio
    float area_cerchio; // Area del cerchio

    // Assegnazione del valore del raggio
    r = 0.0003;

    // Calcolo dell'area del cerchio utilizzando la formula A = πr^2
    area_cerchio = r * r * pigreco;

    // Stampa dell'area del cerchio
    printf("L'area del cerchio è: %f \n \n", area_cerchio);

    /* Definizioni di formato:
     * %d - per un intero decimale
     * %f - per un numero in virgola mobile
     * %e - per un numero in virgola mobile in notazione scientifica
     * %p - per un indirizzo (o puntatore)
     */
    
    // Il programma termina con successo
    return 0;
}
