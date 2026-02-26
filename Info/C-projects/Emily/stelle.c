#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define c 299792458
#define kb 1.380658e-23
#define h 6.626069e-34

void rAsk_par(double *T, int *N) {
   do{ 
        printf("inserisci la temperatura superficiale della stella in °K superiore a  3000° e inferiore a 15000° ");
        scanf("%lf", T);
        printf("inserisci il numero N>= 10000 dei punti con cui fare il grafico");
        scanf("%d", N);
   } while(*N<10000 || (*T>15000 || *T<3000));
}
   
double bose(double x) {
    return 1/(exp(x)-1);
}

double blackbody(double lambda, double T){
    lambda = lambda*pow(10,-9); //conversione in m
    double plambda;
    double x = ((h*c)/(lambda*kb*(T)));
    plambda = ((2* M_PI *h*c*c)/ pow(lambda,5))*(bose(x));
    return plambda/(pow(10,12));
    
}

void ask_lambda(double *plmin, double *plmax){
    do{
        printf("inserisci il valore minimo >100 dell'onda");
        scanf("%lf", plmin);
        printf("inserisci il valore massimo (maggiore del minimo e minore di 10000 dell'onda");
        scanf("%lf", plmax);
    } while(*plmin<100 || (*plmax<*plmin || *plmin>1000));
}

void crea_graf(double *P, double *Vlambda, int *N, double T, double *plmax, double *plmin){
    double dl=(*plmax- *plmin)/(*N - 1);
    Vlambda[0]=*plmin;
    P[0] = blackbody(*plmin, T);
    printf("Culo");
    for(int i=1; i<*N; i++) {
       Vlambda[i]=*plmin + i * dl;
       P[i]=blackbody(Vlambda[i], T);
    }
}

void print(double *P, double *Vlambda, int *N) {
    FILE *file = fopen("dati.txt", "w");
    for(int i=0; i<*N; i++){
        fprintf(file, "%lf %lf\n", Vlambda[i], P[i]);
        printf("i valori del %d elemento del vettore Vlambda[%d] è: %lf e del vettore P[%d] è %lf", i+1, i, i, Vlambda[i], P[i]);
    }
    fclose(file);
    system("gnuplot -p < bb.gp");
}

int main() {  
    int N;
    double T;
    double lambda=0;
    double t=0;
    double lmin, lmax, *P, *Vlambda;
    rAsk_par(&T, &N);
    printf("inserisci lambda in nm");
    scanf("%lf", &lambda);
    t =blackbody(lambda, T);
    printf("il valore dell'equazione è:%lf kW/m^2 nm", t);
    ask_lambda(&lmin,&lmax);
    P = calloc(N, sizeof(double));
    Vlambda = calloc(N, sizeof(double));
    crea_graf(P, Vlambda, &N, T, &lmax, &lmin);
    print(P, Vlambda, &N);
    free(P);
    free(Vlambda);
    return 0;
}