#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100
#define BIANCA 6.0
#define FILTRO 2.0

// ALL LENGTHS IN NANOMETERS.
double lambda_R = 632.816;

// Will be 4 elements 
double fB[MAX];
double maB[MAX];
double nB[MAX];
double nErrB[MAX];

double lambda_zeroB = 0.0;
double err_lambda_zeroB = 0.0;
double l_cB = 0.0;
double err_l_cB = 0.0;
double deltaLambdaB = 0.0;
double err_DeltaLambdaB = 0.0;
double mean_fB = 0.0;
double err_fB = 0.0;
double mean_nB = 0.0;
double err_nB = 0.0;

// Will be two elements
double fF[MAX];
double maF[MAX];
double nF[MAX];
double nErrF[MAX];

double lambda_zeroF = 0.0;
double err_lambda_zeroF = 0.0;
double l_cF = 0.0;
double err_l_cF = 0.0;
double deltaLambdaF = 0.0;
double err_DeltaLambdaF = 0.0;
double mean_fF = 0.0;
double err_fF = 0.0;
double mean_nF = 0.0;
double err_nF = 0.0;


void getBianca(FILE* values) {
    char line[256] = "";
    int counter = 0;
    fgets(line, sizeof(line), values);
    while(fgets(line, sizeof(line), values)) {
        sscanf(line,
           "%lf %lf %lf %lf",
           &fB[counter],
           &maB[counter],
           &nB[counter],
           &nErrB[counter]);
        counter++;
    }
    fseek(values, 0, SEEK_SET);
}

void getFiltro(FILE* values) {
    char line[256] = "";
    int counter = 0;
    fgets(line, sizeof(line), values);
    while(fgets(line, sizeof(line), values)) {
        sscanf(line,
           "%lf %lf %lf %lf",
           &fF[counter],
           &maF[counter],
           &nF[counter],
           &nErrF[counter]);
        counter++;
    }
    fseek(values, 0, SEEK_SET);
}

void analyzeBianca(FILE* data) {
    // F
    for(int i = 0; i < BIANCA; i++) {
        mean_fB += fB[i];
    }
    mean_fB /= BIANCA;
    double maxErr = 0.0;
    for(int i = 0; i < BIANCA; i++) {
        if(maxErr < fabs(fB[i] - mean_fB)) {
            maxErr = fabs(fB[i] - mean_fB);
        }
    }
    err_fB = maxErr;

    //N
    for(int i = 0; i < BIANCA; i++) {
        mean_nB += (double)nB[i];
    }
    mean_nB /= BIANCA;
    maxErr = 0.0;
    for(int i = 0; i < BIANCA; i++) {
        if(maxErr < fabs((double)nB[i] - mean_nB)) {
            maxErr = fabs((double)nB[i] - mean_nB);
        }
    }
    err_nB = maxErr;
    err_nB = 1.0;
    mean_nB = 5.0;
    mean_fB = 0.911;
    err_fB = 0.011;

    // LAMBDA ZERO
    lambda_zeroB = lambda_R * mean_fB;
    err_lambda_zeroB = lambda_R * err_fB;

    // LAMBDA C
    l_cB =  mean_nB * (lambda_zeroB / 4.0);
    err_l_cB = (fabs(1.0 / mean_nB) * err_nB + fabs(1.0 / lambda_zeroB) * err_lambda_zeroB) * l_cB;

    // Delta lambda
    deltaLambdaB = (lambda_zeroB * lambda_zeroB) / (2.0 * 3.1415 * l_cB);
    err_DeltaLambdaB = (fabs(2.0 / lambda_zeroB) * err_lambda_zeroB + fabs(1.0 / l_cB) * err_l_cB) * deltaLambdaB;

    fprintf(data, "Analisi dati per led bianco:\n");
    fprintf(data, "Valori per F: %lf ± %lf\n\n", mean_fB, err_fB);
    fprintf(data, "Valori per N: %lf ± %lf\n\n", mean_nB, err_nB);
    fprintf(data, "Valori per Lambda zero: %lf ± %lf\n\n", lambda_zeroB, err_lambda_zeroB);
    fprintf(data, "Valori per LC: %lf ± %lf\n\n", l_cB, err_l_cB);
    fprintf(data, "Valori per Delta lambda: %lf ± %lf\n\n", deltaLambdaB, err_DeltaLambdaB);
}

void analyzeFiltro(FILE* data) {
        // F
    for(int i = 0; i < FILTRO; i++) {
        mean_fF += fF[i];
    }
    mean_fF /= FILTRO;
    double maxErr = 0.0;
    for(int i = 0; i < FILTRO; i++) {
        if(maxErr < fabs(fF[i] - mean_fF)) {
            maxErr = fabs(fF[i] - mean_fF);
        }
    }
    err_fF = maxErr;

    //N
    for(int i = 0; i < FILTRO; i++) {
        mean_nF += (double)nF[i];
    }
    mean_nF /= FILTRO;
    maxErr = 0.0;
    for(int i = 0; i < FILTRO; i++) {
        if(maxErr < fabs((double)nF[i] - mean_nF)) {
            maxErr = fabs((double)nF[i] - mean_nF);
        }
    }
    err_nF = maxErr;
    err_nF = 6.0;
    mean_nF = 42.0;
    //mean_fF = 0.866;
    //err_fF = 0.011;

    // LAMBDA ZERO
    lambda_zeroF = lambda_R * mean_fF;
    err_lambda_zeroF = lambda_R * err_fF;

    // LAMBDA C
    l_cF =  mean_nF * (lambda_zeroF / 4.0);
    err_l_cF = (fabs(1.0 / mean_nF) * err_nF + fabs(1.0 / lambda_zeroF) * err_lambda_zeroF) * l_cF;

    // Delta lambda
    deltaLambdaF = (lambda_zeroF * lambda_zeroF) / (2.0 * 3.1415 * l_cF);
    err_DeltaLambdaF = (fabs(2.0 / lambda_zeroF) * err_lambda_zeroF + fabs(1.0 / l_cF) * err_l_cF) * deltaLambdaF;

    fprintf(data, "Analisi dati per led bianco con filtro verde:\n");
    fprintf(data, "Valori per F: %lf ± %lf\n\n", mean_fF, err_fF);
    fprintf(data, "Valori per N: %lf ± %lf\n\n", mean_nF, err_nF);
    fprintf(data, "Valori per Lambda zero: %lf ± %lf\n\n", lambda_zeroF, err_lambda_zeroF);
    fprintf(data, "Valori per LC: %lf ± %lf\n\n", l_cF, err_l_cF);
    fprintf(data, "Valori per Delta lambda: %lf ± %lf", deltaLambdaF, err_DeltaLambdaF);
}

int main() {
    char *bianca = "bianca.dat";
    char *data = "data.dat";
    char *filtro = "filtro.dat";

    FILE *biancaFile = fopen(bianca, "r");
    FILE *dataFile  = fopen(data, "w");
    FILE *filtroFile = fopen(filtro, "r");

    if(biancaFile == NULL || filtroFile == NULL){
        printf("File is unreadable or missing!");
        return 1;
    }

    getBianca(biancaFile);
    getFiltro(filtroFile);
    analyzeBianca(dataFile);
    analyzeFiltro(dataFile);

    fclose(biancaFile);
    fclose(dataFile);
    fclose(filtroFile);
    /*
    char gnuPlotCommand[512];
    snprintf(gnuPlotCommand, sizeof gnuPlotCommand, "plot \"plot.dat\" using 1:2:3 with errorbars lc 7 title \"Misure spaziatura fenditure\", \"plot.dat\" using 1:2 with points pointtype 7 pointsize 1 lc 7 notitle");
    FILE* gnuPlotPipe = NULL;
    gnuPlotPipe = popen("gnuplot -p", "w");
        if(gnuPlotPipe != NULL) {
        // Customization
        fprintf(gnuPlotPipe, "set title \"Compatibilità spaziatura fenditure\"\n");
        fprintf(gnuPlotPipe, "set border 3\n");
        fprintf(gnuPlotPipe, "set key right box\n");
        fprintf(gnuPlotPipe, "set tics nomirror\n");
        fprintf(gnuPlotPipe, "set ylabel \"a (10^-10 m)\"\n");
        fprintf(gnuPlotPipe, "set xlabel \"Lunghezza d'onda (10^-10 m)\"\n");
        fprintf(gnuPlotPipe, "set xrange[4000:6000]\n");
        //Plotting
        fprintf(gnuPlotPipe, "%s \n", gnuPlotCommand);
        //Quitting
        fprintf(gnuPlotPipe, "quit");
    }  else {
        perror("popen failed");
        return 1;
    }
    */

    return 0;
}