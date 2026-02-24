#include <stdio.h>
#include <math.h> // Inclusione della libreria math.h per utilizzare la funzione pow()
#define pigreco 3.141592654 // Definizione della costante per il valore di pi greco

int main()
{
    // Dichiarazione delle variabili per il raggio e l'area del cerchio
    float r;            // Raggio del cerchio
    float area_cerchio; // Area del cerchio

    // Richiesta all'utente di inserire il raggio del cerchio
    printf("Inserisci il raggio: \n");
    scanf("%f", &r);

    // Calcolo dell'area del cerchio utilizzando la formula A = πr^2
    area_cerchio = pow(r, 2) * pigreco;

    // Stampa dell'area del cerchio
    printf("L'area del cerchio è: %f \n \n", area_cerchio);

    // Il programma termina con successo
    return 0;
}
