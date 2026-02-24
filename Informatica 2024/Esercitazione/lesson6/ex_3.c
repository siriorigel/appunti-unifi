#include <stdio.h>
#include <math.h>

#define N 4

int main() {
    int array[N];
    int *p;

    printf("Inserisci i valori per riempire l'array: \n");

    // Iterazione corretta fino a N-1
    for (int i = 0; i < N; i++) {
        scanf("%d", &array[i]);
    }
    
    p = array;  // Assegna al puntatore il primo elemento dell'array

    printf("Valori dell'array:\n");

    // Iterazione corretta per stampare gli elementi dell'array
    for (int i = 0; i < N; i++) {
        printf("%d \t", *(p+i));  // Stampa gli elementi dell'array
    }

    printf("\n");  // Aggiunta di una nuova riga alla fine della stampa

    return 0;  // Indica che il programma termina correttamente
}
