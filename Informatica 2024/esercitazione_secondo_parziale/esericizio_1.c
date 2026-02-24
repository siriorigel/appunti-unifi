/* ----------------------------------------------------------------------------
Equazione di Drake
----------------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define K 7

void Ask_coef(double* coef){
    printf("Inserire i coefficienti della equazione di Drake\n");
    do
    {
        printf("Inserire il coefficiente R: ");
        scanf("%lf", &coef[0]);
        if (coef[0]<=0)
        {
            printf("Errore! Reinserire il coefficiente R\n");
        }
    } while (coef[0]<=0);
    do
    {
        printf("Inserire il coefficiente fp: ");
        scanf("%lf", &coef[1]);
        if (coef[1]<0 || coef[1]>1)
        {
            printf("Errore! Reinserire il coefficiente fp\n");
        }
        
    } while (coef[1]<0 || coef[1]>1);
    do
    {
        printf("Inserire il coefficiente n_e: ");
        scanf("%lf", &coef[2]);
        if (coef[2]<0 || coef[2]>1)
        {
            printf("Errore! Reinserire il coefficiente n_e\n");
        }
    } while (coef[2]<0 || coef[2]>1);
    do
    {
        printf("Inserire il coefficiente f_l: ");
        scanf("%lf", &coef[3]);
        if (coef[3]<0 || coef[3]>1)
        {
            printf("Errore! Reinserire il coefficiente f_l\n");
        }
    } while (coef[3]<0 || coef[3]>1);
    do
    {
        printf("Inserire il coefficiente f_i: ");
        scanf("%lf", &coef[4]);
        if (coef[4]<0 || coef[4]>1)
        {
            printf("Errore! Reinserire il coefficiente f_i\n");
        }
    } while (coef[4]<0 || coef[4]>1);
    do
    {
        printf("Inserire il coefficiente f_c: ");
        scanf("%lf", &coef[5]);
        if (coef[5]<0 || coef[5]>1)
        {
            printf("Errore! Reinserire il coefficiente f_c\n");
        }
    } while (coef[5]<0 || coef[5]>1);
    do
    {
        printf("Inserire il coefficiente L: ");
        scanf("%lf", &coef[6]);
        if (coef[6]<=0)
        {
            printf("Errore! Reinserire il coefficiente L\n");
        }
    } while (coef[6]<=0);
    
}

double Drake(double* coef){
    return (coef[0]*coef[1]*coef[2]*coef[3]*coef[4]*coef[5]*coef[6]);
}

void Chiedi_Errore(double* errore){
    do
    {
        printf("Inserire l'errore: ");
        scanf("%lf", errore);
        if (*errore<0 || *errore>1)
        {
            printf("Errore! Reinserire l'errore\n");
        }
    } while (*errore<0 || *errore>1);
    
}

void param(double* mu, double* sq, double errore, double* coef){
    for (int i = 0; i < K; i++)
    {
        *mu += log(coef[i]);
    }

    for (int i = 0; i < K; i++)
    {
        *sq += pow((log(coef[i])*errore), 2);
    }
}

void Ask_n(int* n){
    do
    {
        printf("Inserire il numero di punti: ");
        scanf("%d", n);
        if (*n<1000)
        {
            printf("Errore! Reinserire il numero di punti\n");
        }
    } while (*n<1000);
}

double lognorm(double N, double mu, double sq){
    return (1./N)*(1./sqrt(2*M_PI*sq))*exp(-pow(log(N)-mu, 2)/(2*sq));
}

void graf(double dn, double* vetN, double* p, double mu, double sq, int n){
    for (int i = 0; i < n; i++)
    {
        vetN[i] = 0.001+i*dn;
        p[i] = lognorm(vetN[i], mu, sq);
    }
    
}

void Print(double* vetN, double* p, int n){
    FILE *fp= fopen("drake.dat", "w");
    for (int i = 0; i < n; i++)
    {
        fprintf(fp, "%lf; %lf\n", vetN[i], p[i]);
    }
    fclose(fp);
    
}

void plotWithGnuplot(const char *datafile, const char *outputfile) {
    FILE *gnuplot = popen("gnuplot -persist", "w");
    if (gnuplot == NULL) {
        perror("Errore nell'apertura di Gnuplot");
        exit(EXIT_FAILURE);
    }
    
    fprintf(gnuplot, "set terminal pngcairo\n"); // Output in formato PNG
    fprintf(gnuplot, "set output '%s'\n", outputfile); // File di output
    fprintf(gnuplot, "plot '%s' using 1:2 with linespoints title 'Numero di Drake'\n", datafile); // Comando per tracciare il grafico
    pclose(gnuplot);
}

int main(){
    double Nd, mu=0.0, sq=0.0, errore, dn;
    double coef[K];
    double *vetN, *p;
    int n;


    Ask_coef(coef);
    Nd = Drake(coef);
    Chiedi_Errore(&errore);
    param(&mu, &sq, errore, coef);
    Ask_n(&n);

    vetN = malloc(n*sizeof(double));
    p = malloc(n*sizeof(double));

    dn = (10*Nd)/(n+1);

    graf(dn, vetN, p, mu, sq, n);
    Print(vetN, p, n);
    plotWithGnuplot("drake.dat", "drake.png");


    free(vetN);
    free(p);
    return 0;
}