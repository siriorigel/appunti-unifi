#include <stdio.h>
#include <math.h>

void media(double *, double [], int );
void deviazione_standard(double *, double [], int , double );

int main() {
    double num[5];
    double m, sigma; //media
    for (int i = 0; i < 5; i++){

        printf("Inserisci numero: ");
        scanf("%lf", &num[i]);
    }

    media(&m, num, 5);

    deviazione_standard(&sigma, num, 5, m);

    printf("La media è: %lf \n", m);
    printf("La deviazione standard è %lf \n", sigma);
}

void media (double *pm, double x[], int N){
    *pm=0;
    for (int i = 0; i < N; i++)
    {
        *pm +=x[i];
    }
    *pm=*pm/N;
    
}

void deviazione_standard(double *somma_quadratica, double x[], int N, double media) {
    *somma_quadratica = 0;
    for (int i = 0; i < N; i++) {
        *somma_quadratica += pow(x[i] - media, 2);  // Somma dei quadrati delle differenze
    }
    float sigma = sqrt(*somma_quadratica / (N-1));  // Deviazione standard
}