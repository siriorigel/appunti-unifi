#include <stdio.h>
#include <math.h>
#include <math.h>

#define BASE 2

int main(void)
{
    int numero_decimale ;
    int N ;
    int bit ;
    int num_bits ;

    /* LEGGI IL NUMERO DECIMALE */
    printf("Inserire il numero decimale da convertire: ") ; 
    scanf("%d", &numero_decimale);

     /* LEGGI IL NUMERO DI BIT */
    printf("Inserisci il numero di bit: ") ;
    scanf("%d", &N) ;

    /* VERIFICA CHE IL NUMERO DI BIT SIA SUFFICIENTE PER RAPPRESENTARE IL NUMERO DECIMALE */
    if ( pow(BASE,N) - 1 < numero_decimale ){
        printf("Errore: il numero di bit e’ insufficiente\n");
    } else
    {   /* INIZIALIZZA "num_bits" A 0 */
        num_bits = 0 ;

        /* IL CICLO CALCOLA LE CIFRE BINARIE PER RAPPRESENTARE IL NUMERO DECIMALE, PARTENDO DALLA CIFRA BINARIA MENO SIGNIFICATIVA (LSB) */ 
        while ( num_bits < N ){
            /* CALCOLA LA CIFRA BINARIA DI PESO "num_bits" */ 
            bit = numero_decimale % BASE ;
            /* CALCOLA IL NUMERO DECIMALE DA DIVIDERE PER "dividendo" ALLA PROSSIMA ESECUZIONE DEL CICLO */
            numero_decimale = numero_decimale/BASE ;
            /* STAMPA IL RISULTATO */
            printf("Cifra binaria di peso 2^%d: %d\n", num_bits, bit) ;
            /* INCREMENTA IL CONTATORE "num_bits" */ num_bits = num_bits + 1 ;
        }
    }
}
