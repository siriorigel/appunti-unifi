#include <stdio.h>
#include <math.h>

int main() {
    float T_f, T_c, T_k; // Dichiarazione delle variabili per le temperature in Fahrenheit, Celsius e Kelvin
    char C, K;           // Variabili per memorizzare le scelte dell'utente

    // Introduzione al programma
    printf("Benvenuto nel convertitore di temperature!\n");

    // Richiesta all'utente di selezionare la tipologia di temperatura da convertire
    printf("Seleziona la tipologia di temperatura che vuoi convertire: \n F - Fahrenheit \n C - Celsius \n K - Kelvin \n");
    scanf(" %c", &C); // Nota: aggiunto spazio prima di %c per evitare problemi di buffer

    if (C == 'C') {
        // Conversione da Celsius a altre unità
        printf("Seleziona la tipologia di conversione che vuoi eseguire: \n F - Celsius to Fahrenheit  \n K - Celsius to Kelvin \n");
        scanf(" %c", &K); // Nota: aggiunto spazio prima di %c per evitare problemi di buffer

        if (K == 'F') {
            // Conversione da Celsius a Fahrenheit
            printf("Inserisci la temperatura in Celsius:\n");
            scanf("%f", &T_c);
            T_f = (T_c * 9.0 / 5.0) + 32;
            printf("La temperatura in Fahrenheit è: %f\n", T_f);
        } else if (K == 'K') {
            // Conversione da Celsius a Kelvin
            printf("Inserisci la temperatura in Celsius:\n");
            scanf("%f", &T_c);
            T_k = T_c + 273.15;
            printf("La temperatura in Kelvin è: %f\n", T_k);
        }
    } else if (C == 'F') {
        // Conversione da Fahrenheit a altre unità
        printf("Seleziona la tipologia di conversione che vuoi eseguire: \n C - Fahrenheit to Celsius  \n K - Fahrenheit to Kelvin \n");
        scanf(" %c", &K); // Nota: aggiunto spazio prima di %c per evitare problemi di buffer

        if (K == 'C') {
            // Conversione da Fahrenheit a Celsius
            printf("Inserisci la temperatura in Fahrenheit:\n");
            scanf("%f", &T_f);
            T_c = (T_f - 32) * 5.0 / 9.0;
            printf("La temperatura in Celsius è: %f\n", T_c);
        } else if (K == 'K') {
            // Conversione da Fahrenheit a Kelvin
            printf("Inserisci la temperatura in Fahrenheit:\n");
            scanf("%f", &T_f);
            T_c = (T_f - 32) * 5.0 / 9.0;
            T_k = T_c + 273.15;
            printf("La temperatura in Kelvin è: %f\n", T_k);
        }
    } else if (C == 'K') {
        // Conversione da Kelvin a altre unità
        printf("Seleziona la tipologia di conversione che vuoi eseguire: \n C - Kelvin to Celsius  \n F - Kelvin to Fahrenheit \n");
        scanf(" %c", &K); // Nota: aggiunto spazio prima di %c per evitare problemi di buffer

        if (K == 'C') {
            // Conversione da Kelvin a Celsius
            printf("Inserisci la temperatura in Kelvin:\n");
            scanf("%f", &T_k);
            T_c = T_k - 273.15;
            printf("La temperatura in Celsius è: %f\n", T_c);
        } else if (K == 'F') {
            // Conversione da Kelvin a Fahrenheit
            printf("Inserisci la temperatura in Kelvin:\n");
            scanf("%f", &T_k);
            T_c = T_k - 273.15;
            T_f = (T_c * 9.0 / 5.0) + 32;
            printf("La temperatura in Fahrenheit è: %f\n", T_f);
        }
    } else {
        // Gestione di un'opzione non supportata
        printf("Selezione non valida! Assicurati di selezionare una delle opzioni supportate (F, C o K).\n");
    }

    return 0; // Il programma termina con successo
}
