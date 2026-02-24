#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N 100

int main(){
    int a[N];
    int sum = 0;

    int k=0, found = 0;

    printf("Inserisci i dati da inserire dentro l'array \nScrivi '-1' per interrompere l'immissione \n");

    scanf("%d", &k);

    for (int i = 0; i < N && k != -1; i++)
    {
        a[i]=k;
        sum += a[i];
        printf("La somma parziale è: %d \n", sum);
        scanf("%d", &k);
        if(k==-1){
            printf("Hai inserito tutti i dati! \nLa somma è: %d \n", sum);
        }
    }
        


}
