/*

Voli di Levy

*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double step_LB(double MFP){
    double xi = 0.0;
    xi = ((double)rand() / (double)RAND_MAX)*1;
    return -MFP * log(xi);
}

double step_Levy(double MFP, double k){
    double xi = 0.0;
    xi = ((double)rand() / (double)RAND_MAX)*1;
    return xi*((1/k)-1)*(pow(xi,-k)-1);
}

void Ask_RW(double *MFP, double *k, int *Nsteps){
    printf("MFP: ");
    scanf("%lf", MFP);
    printf("Nsteps: ");
    scanf("%d", Nsteps);
    do{
        printf("k: ");
        scanf("%lf", k);
        if(*k<=0 || *k>1){
            printf("k deve essere maggiore di 0 e minore di 1\n");
    }
    }while(*k<=0 || *k>1);
}

double Gen_Step(double MFP, double k){
    if (k==0)
    {
        return step_LB(MFP);
    }
    else{
        return step_Levy(MFP, k);
    }

    
}

double Gen_ang(){
    double xi = 0.0;
    xi = ((double)rand() / (double)RAND_MAX)*2*M_PI;
    return xi;
}

void Print_RW(double *x, double *y, int *Nsteps, char c[]){
    FILE *fp;
    fp = fopen(c, "w");
    for (int i = 0; i < *Nsteps; i++)
    {
        fprintf(fp, "%lf %lf\n", x[i], y[i]);
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
    fprintf(gnuplot, "plot '%s' using 1:2 with linespoints title 'Volo di Levy'\n", datafile); // Comando per tracciare il grafico
    pclose(gnuplot);
}

int main(){
    srand(time(NULL));

    double MFP = 0.0, k = 0.0;
    int Nsteps=0;

    Ask_RW(&MFP, &k, &Nsteps);

    double x[Nsteps];
    double y[Nsteps];
    double theta[Nsteps];
    double l[Nsteps];


    for (int i = 0; i < Nsteps; i++)
    {
        x[i] = 0.0;
        y[i] = 0.0;
        theta[i] = Gen_ang();
        l[i] = Gen_Step(MFP, k);
        x[i] = x[i-1] + l[i]*cos(theta[i]);
        y[i] = y[i-1] + l[i]*sin(theta[i]);
    }

    Print_RW(x, y, &Nsteps, "RW.dat");
    plotWithGnuplot("RW.dat", "RW.png");


    return 0;

}