/*------------------------------------------------------------------------------------------------------------
Esercizio: Scambia tra di loro i valori di due variabii usando una variabile ausiliaria e due puntatori.
-------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    // Dichiarazione delle variabili
    int a, b, c;  // 'a' e 'b' sono per i valori input, 'c' è una variabile temporanea per lo scambio
    int *p, *k;  // 'p' e 'k' sono puntatori per manipolare le variabili

    // Chiede all'utente di inserire valori per 'a' e 'b'
    printf("Inserisci un valore da assegnare alla variabile a: ");
    scanf("%d", &a);  // Legge il valore inserito dall'utente e lo memorizza in 'a'
    printf("Inserisci un valore da assegnare alla variabile b: ");
    scanf("%d", &b);  // Legge il valore inserito dall'utente e lo memorizza in 'b'

    // Stampa i valori di 'a' e 'b' prima dello scambio
    printf("Il valore di a è %d, mentre il valore di b è %d \n", a, b);

    // Messaggio che indica l'inizio dello scambio
    printf("Procedo allo scambio… \n");

    // Assegnazione dei puntatori 'p' e 'k' ai rispettivi indirizzi di 'a' e 'b'
    p = &a;  // 'p' punta all'indirizzo di 'a'
    k = &b;  // 'k' punta all'indirizzo di 'b'

    // Scambio dei valori utilizzando la variabile temporanea 'c'
    c = *p;  // 'c' prende il valore a cui punta 'p', ovvero 'a'
    a = *k;  // 'a' viene sostituito con il valore a cui punta 'k', ovvero 'b'
    b = c;  // 'b' prende il valore originale di 'a' dalla variabile temporanea 'c'

    // Stampa i valori di 'a' e 'b' dopo lo scambio
    printf("Il valore di a adesso è %d, mentre il valore di b è %d \n", a, b);  // Mostra il risultato dello scambio

    return 0;  // Indica che il programma è terminato con successo
}
