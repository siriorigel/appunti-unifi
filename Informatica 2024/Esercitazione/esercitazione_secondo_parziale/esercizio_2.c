/* ------------------------------------------------------------------------------

Legge di Lambert-Beer

-------------------------------------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double Ask_mu(){
    double mu;
    printf("Inserisci mu [mm^(-1)]: ");
    scanf("%lf", &mu);
    return mu;
}

void Ask_LB(double *pw, double *pdz, int *pN, double *pI0, double mu){
    do
    {
        printf("Inserisci w [mm]: ");
        scanf("%lf", pw);
        if (*pw < 2/mu)
        {
            printf("w deve essere maggiore di 2/mu\n");
        }
        
    } while (*pw < 2/mu);
    do
    {
        printf("Inserisci N: ");
        scanf("%d", pN);
        if (*pN < 50)
        {
            printf("N deve essere maggiore di 50\n");
        }
        
    } while (*pN<50);
    
    printf("Inserisci I0 [mW/mm^2]: ");
    scanf("%lf", pI0);  
    
    *pdz = *pw / (*pN - 1 );
}

double LB(double I0, double z, double mu){
    return I0 * exp(-z*mu);
}

void graf_LB(double z[], double I[], int N, double mu, double dz, double I0){
    for (int i = 0; i < N; i++)
    {   
        z[i] = i * dz;
        I[i] = LB(I0, z[i], mu);
    }
}

void PrintLB(double z[], double I[], int N, char c[]){
    FILE *fp;
    fp = fopen(c, "w");
    for (int i = 0; i < N; i++)
    {
        fprintf(fp, "%lf\t%lf\n", z[i], I[i]);
    }
    fclose(fp);
}

void plotWithGnuplot(char *datafile, char *outputfile) {
    FILE *gnuplot = popen("gnuplot -persist", "w");
    if (gnuplot == NULL) {
        perror("Errore nell'apertura di Gnuplot");
        exit(EXIT_FAILURE);
    }
    
    fprintf(gnuplot, "set terminal pngcairo\n"); // Output in formato PNG
    fprintf(gnuplot, "set output '%s'\n", outputfile); // File di output
    fprintf(gnuplot, "plot '%s' using 1:2 with linespoints title 'Lamberth-Beer'\n", datafile); // Comando per tracciare il grafico
    pclose(gnuplot);
}

int main(){
    double mu = Ask_mu(), w, dw, dz, I0;
    int N;
    double *z, *I;

    Ask_LB(&w, &dw, &N, &I0, mu);

    z = malloc(N * sizeof(double));
    I = malloc(N * sizeof(double));

    graf_LB(z, I, N, mu, dz, I0);
    PrintLB(z, I, N, "LB.dat");
    plotWithGnuplot("LB.dat", "LB.png");

    free(z);
    free(I);

    return 0;

}
