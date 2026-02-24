#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Chiedi_n(int* n) {
    do {
        printf("Inserisci un numero maggiore di 0 e minore di 1'000'000: ");
        scanf("%d", n); 
    } while (*n <= 0 || *n > 1000000);
}

void genera_vettore(double* p, int n){
        for (int i = 0; i < n; i++) {
        p[i] = ((double)rand() / (double)RAND_MAX) * 100; 
    }
}

void stampa_vettore(double* p, int n){
        printf("Vettore:\n");
            for (int i = 0; i < n; i++) {
                printf("%lf \n", p[i]);
            }
            printf("\n");
}

int main() {
    srand(time(NULL));

    int n; 
    Chiedi_n(&n); 

    double* p = (double*)calloc(n, sizeof(double)); 

    if (p == NULL) {
        printf("Errore: impossibile allocare memoria.\n");
        return EXIT_FAILURE; 
    }

    genera_vettore(p, n);

    stampa_vettore(p, n);

    free(p); 

    return 0;
}
