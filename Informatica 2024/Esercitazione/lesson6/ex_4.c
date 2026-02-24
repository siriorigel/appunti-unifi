#include <stdio.h>

void media(double *, double [], int );

void main() {
    double num[5];
    double m; //media
    for (int i = 0; i < 5; i++){

        printf("Inserisci numero: ");
        scanf("%lf", num[i]);
    }

    media(&m, num, 5);

    printf("La media è: %lf \n", m);
    
}

void media (double *pm, double x[], int N){
    *pm=0;
    for (int i = 0; i < N; i++)
    {
        *pm +=x[i];
    }
    *pm=*pm/N;
    
}