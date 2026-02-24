#include <stdio.h>
#include <math.h>

int main() {
    float T_f, T_c; // Dichiarazione delle variabili per la temperatura in Fahrenheit e Celsius
    char C;         // Variabile per memorizzare la scelta dell'utente

    // Richiesta all'utente di selezionare la tipologia di conversione
    printf("Seleziona la tipologia di conversione.\n C - Fahrenheit to Celsius. \n F - Celsius to Fahrenheit \n ");
    scanf(" %c", &C); // Nota: aggiunto spazio prima di %c per evitare problemi di buffer

    if (C == 'C') {
        // Conversione da Fahrenheit a Celsius
        printf("Inserisci la temperatura in Fahrenheit:\n");
        scanf("%f", &T_f);

        T_c = (T_f - 32) * 5.0 / 9.0; // Formula di conversione da Fahrenheit a Celsius

        printf("La temperatura in Celsius è: %f\n", T_c);
    } else if (C == 'F') {
        // Conversione da Celsius a Fahrenheit
        printf("Inserisci la temperatura in Celsius:\n");
        scanf("%f", &T_c);

        T_f = (T_c * 9.0 / 5.0) + 32; // Formula di conversione da Celsius a Fahrenheit

        printf("La temperatura in Fahrenheit è: %f\n", T_f);
    } else {
        // Gestione di un'opzione non supportata
        printf("Conversione non supportata! \n");
    }

    return 0; // Il programma termina con successo
}
