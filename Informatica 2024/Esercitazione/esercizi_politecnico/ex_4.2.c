/*----------------------------------------------------------------------------------------------------------------------------------------
4.3 Somma di un numero di valori indefinito

Si scriva un programma in linguaggio C per calcolare la somma di un insieme di numeri inseriti da tastiera. Il programma deve:
• leggere una sequenza di numeri
• fermarsi non appena viene inserito il numero 0
• visualizzare il valore corrispondente alla somma dei valori introdotti.
----------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
    float num, x; //Dichiaro le variabili che andrò ad utilizzare all'interno del ciclo while

    printf("Inserisci una sequenza di numeri: \n"); //Mostro la richiesta di partenza all'user

    //Ciclo while per la somma
    while (num !=0)
    {
        scanf("%f", &num);
        x += num;
    }

    printf("La somma della sequenza inserita è: %f; \n", x);
    
}