#include <stdio.h>
#include <math.h>

int main() {
    float T_f, T_c; // Dichiarazione delle variabili per la temperatura in Fahrenheit e Celsius

    // Introduzione al programma
    printf("Questo programma converte una temperatura da Fahrenheit a Celsius e verifica se la temperatura convertita è inferiore a 10°C.\n");

    // Acquisizione della temperatura in Fahrenheit dall'utente
    printf("Inserisci la temperatura in Fahrenheit: \n");
    scanf("%f", &T_f);

    // Calcolo della temperatura in Celsius
    T_c = 5.0 / 9.0 * (T_f - 32);

    // Stampa della temperatura in Celsius
    printf("La temperatura in Celsius è: %f\n", T_c);

    // Verifica se la temperatura in Celsius è inferiore a 10°C e stampa un messaggio appropriato
    if (T_c < 10) {
        printf("Madonna che freddo \n");
    }

    return 0; // Il programma termina con successo
}
