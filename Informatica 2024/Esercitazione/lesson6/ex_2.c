/*------------------------------------------------------------------------------------------------------------
Esercizio: Scambia tra di loro i valori di due variabii usando una variabile ausiliaria e due puntatori.
-------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

void scambio_valori(int *p, int *k){

    int c = *p;  // 'c' prende il valore a cui punta 'p', ovvero 'a'
    *p = *k;  // Il valore a cui punta 'p' viene sostituito con il valore a cui punta 'k', ovvero 'b'
    *k = c;  // Il valore a cui punta 'k' prende il valore originale di 'a' dalla variabile temporanea 'c'
}

int main(){
    int a,b;


    // Chiede all'utente di inserire valori per 'a' e 'b'
    printf("Inserisci un valore da assegnare alla variabile a: ");
    scanf("%d", &a);  // Legge il valore inserito dall'utente e lo memorizza in 'a'
    printf("Inserisci un valore da assegnare alla variabile b: ");
    scanf("%d", &b);  // Legge il valore inserito dall'utente e lo memorizza in 'b'

    // Stampa i valori di 'a' e 'b' prima dello scambio
    printf("Il valore di a è %d, mentre il valore di b è %d \n", a, b);

    scambio_valori(&a,&b);

    // Stampa i valori di 'a' e 'b' dopo lo scambio
    printf("Il valore di a adesso è %d, mentre il valore di b è %d \n", a, b);  // Mostra il risultato dello scambio
}