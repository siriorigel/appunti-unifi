/*----------------------------------------------------------------------------------------------------------------------------------------
4.4 Conteggio dei numeri inseriti
Un utente inserisce da tastiera una serie di numeri interi positivi, ed il termine della serie è indicato dall’inserimento del valore -1. 
Il programma, al termine dell’inserimento, deve stampare quanti numeri pari l’utente aveva inserito, e quanti numeri in totale sono stati inseriti.
----------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
    int num; //Dichiaro le variabili che andrò ad utilizzare all'interno del ciclo while
    int i=0;
    int x= 1;

    printf("Inserisci una sequenza di numeri interi: \n"); //Mostro la richiesta di partenza all'user

    //Ciclo while per la somma
    while (num !=-1)
    {
        scanf("%d", &num);
        x ++;

        if (num%2==0)
        {
            i = i+1;
        }
        
    }
    printf("Hai inserito %d numeri, di cui %d sono pari \n", x, i);

}