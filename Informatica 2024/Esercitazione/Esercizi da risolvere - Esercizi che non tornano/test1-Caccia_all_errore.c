/*------------------------------------------------------------------------------------------------------------------------
Questo è un esericizio di test.

Questa sezione scritta in questo modo è l'introduzione dove potrete inserire la consegna in modo tale da ottimizzare la 
collaborazione con tutti i membri all'interno di questa repository!
-------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

int main() {
    int numero;
    printf("Inserisci un numero intero: ");
    scanf("%d", numero); /*In questo caso manca il puntatore "&" per salvare il nuovo valore sulla variabile numero*/
    
    printf("Il doppio del numero inserito è: %d\n", 2 * numero);
    
    return 0;
}
