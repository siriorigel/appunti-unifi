/*
Programma per il Metodo dei Minimi Quadrati
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void ask_misure(int* n){
    printf("Inserisci il numero di misure: ");
    scanf("%d", n);
}

void Calcolo_Delta(double *x, double *y, double *delta, int n){
    double firsterm = 0;
    double secondterm  = 0;
    
    for(int i = 0; i < n; i++){
        firsterm += (pow(x[i], 2));
        secondterm += (x[i]);
    }
    *delta = n*firsterm - (pow(secondterm, 2));
}

void Calcolo_A(double *x, double *y, double *a, int n, double delta){
    double firsterm = 0;
    double secondterm = 0;
    double thirdterm = 0;
    double fourthterm = 0;

    for (int i = 0; i < n; i++)
    {
        firsterm += pow(x[i], 2);
        secondterm += (y[i]);
        thirdterm += (x[i]);
        fourthterm += (x[i]*y[i]);
    }

    *a = (firsterm*secondterm - thirdterm*fourthterm)/ delta ;

}

void Calcolo_B(double *x, double *y, double *b, int n, double delta, double a){
    double firsterm = 0;
    double secondterm = 0;
    double thirdterm = 0;

    for (int i = 0; i < n; i++)
    {
        firsterm += (x[i]*y[i]);
        secondterm += (x[i]);
        thirdterm += (y[i]);
    }

    *b = (n*firsterm - secondterm*thirdterm)/delta;

}

void Assegna_delta_y(double *delta_y, int n){
    double Dy;
    printf("Inserisci i valori di delta_y: ");
    scanf("%lf", &Dy);

    for (int i = 0; i < n; i++)
    {
        delta_y[i] = Dy;
    }
}

void sigma_y(double* x, double *y, double* sigma_y, int n, double a, double b){
    double firstterm = 0;

    for (int i = 0; i < n; i++)
    {
        firstterm += (pow((y[i]-a-b*x[i]), 2));
    }
    *sigma_y = sqrt((1./n-2)*firstterm);

}

void sigma_a(double* x, double *y, double* sigma_a, int n, double a, double b, double sigma_y, double delta){
    double firstterm = 0;

    for (int i = 0; i < n; i++)
    {
        firstterm += pow(x[i], 2);
    }
    *sigma_a = sigma_y * sqrt(firstterm/delta);
    
}

void sigma_b(double sigma_y, int n, double delta, double* sigma_b){
    *sigma_b = sigma_y * sqrt(n/delta);
}


int main()
{
    double *x, *y, delta, a, b, *delta_y, Sigma_a, Sigma_b, Sigma_y;
    int n;

    ask_misure(&n);

    x = malloc(n * sizeof(double));
    y = malloc(n * sizeof(double));
    delta_y = malloc(n * sizeof(double));

    Calcolo_Delta(x, y, &delta, n);
    Calcolo_A(x, y, &a, n, delta);
    Calcolo_B(x, y, &b, n, delta, a);
    Assegna_delta_y(delta_y, n);
    sigma_y(x, y, &Sigma_y, n, a, b);
    sigma_a(x, y, &Sigma_a, n, a, b, Sigma_y, delta);
    sigma_b(Sigma_y, n, delta, &Sigma_b);

    printf("a = %lf +- %lf\n", a, Sigma_a);
    printf("b = %lf +- %lf\n", b, Sigma_b);
    printf("Sigma_y = %lf \n", Sigma_y);


    return 0;
}

// Ex_3.c