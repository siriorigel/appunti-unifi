#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 5

int main(){
    double x[5], y[5], Ey[5];

    FILE *fp;
    if((fp=fopen("misure.dat", "r"))== NULL){
        printf("Errore di apertura del file!\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < N; i++)
    {
        fscanf(fp, "%lf %lf %lf", &x[i], &y[i], &Ey[i]);
    }

    for (int i = 0; i < N; i++)
    {
        printf("%lf %lf %lf \n", x[i], y[i], Ey[i]);
    }
    
    int err;
    err = system("ls scr.gp");
    if (err!=0)
    {
        printf("Script per l'esecuzione di gnuplot non trovato! \n");
        exit(0);
    } else {
        printf("Visualizzazione del risultato… \n");
        system("gnuplot < scr.gp");
    }
}