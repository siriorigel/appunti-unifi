#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double yellow = 0.0;
double greenYellow = 0.0;
double green = 0.0;
double darkGreen = 0.0;
double blue = 0.0;
double violet = 0.0;
double purple = 0.0;

double yellowTheta = 0.0;
double greenYellowTheta = 0.0;
double greenTheta = 0.0;
double darkGreenTheta = 0.0;
double blueTheta = 0.0;
double violetTheta = 0.0;
double purpleTheta = 0.0;

double a = 0.0;
double da = 0.0;
double n = 0.0;
double dn = 0.0;

double t = 0.0;
double t1 = 0.0;
double tErr = 0.0;

double deltaL = 0.01; // Armstrong
double deltaT = 0.00166; // Radiants

void getTheta(FILE* values) {
    char line[256];
    double skip, theta;
    int counter = 0;

    fseek(values, 0, SEEK_SET);

    while (fgets(line, sizeof(line), values)) {
        if (sscanf(line, "%lf %lf", &skip, &theta) != 2)
            continue;

        switch (counter) {
            case 0: purpleTheta = theta; break;
            case 1: violetTheta = theta; break;
            case 2: blueTheta = theta; break;
            case 3: darkGreenTheta = theta; break;
            case 4: greenTheta = theta; break;
            case 5: greenYellowTheta = theta; break;
            case 6: yellowTheta = theta; break;
        }
        counter++;
    }

    fseek(values, 0, SEEK_SET);
}

void getElements(FILE* values) {
    char line[256] = "";
    int counter = 0;
    while(fgets(line, sizeof(line), values)) {
        switch (counter)
        {
        case 0: purple = atof(line);
            break;
        case 1: violet = atof(line);
            break;
        case 2: blue = atof(line);
            break;
        case 3: darkGreen = atof(line);
            break;
        case 4: green = atof(line);
            break;
        case 5: greenYellow = atof(line);
            break;
        case 6: yellow = atof(line);
            break;
        default:
            break;
        }
        counter++;
    }
    fseek(values, 0, SEEK_SET);
}

double getSigma(double val, double sigma) {
    return (abs(val - 16666.66)) / (sigma);
}

void getN() {
    n = (1.0 / a) * pow(10, 7);
    dn = (1.0 / (a * a)) * da * pow(10, 7);
}

void getA(double l, double dT) {
    a = l / (sin(dT));
    //da = abs(deltaL  / sin(dT)) + deltaT * abs((-l * cos(dT)) / (sin(dT) * sin(dT)));
    da = ((1.0 / l) * deltaL + fabs((cos(dT) / sin(dT))) * deltaT) * a;
    getN();
    t += a*da;
    t1 += da;
    tErr += 1.0 / (da * da);
}

int main() {
    char *values = "values.dat";
    char *data = "data.dat";
    char *plot = "plot.dat";

    FILE *valueFile = fopen(values, "r");
    FILE *dataFile  = fopen(data, "w");
    FILE *plotFile = fopen(plot, "w");

    if(valueFile == NULL){
        printf("File is unreadable or missing!");
        return 1;
    }

    getElements(valueFile);
    getTheta(valueFile);

    fprintf(dataFile, "Ecco i valori di a pm Delta a\n");
    getA(purple, purpleTheta);
    fprintf(dataFile, "I valori per la lunghezza viola: \n");
    fprintf(dataFile, "%lf pm %lf A\n", a, da);
    fprintf(dataFile, "Numero di linee nel reticolo: \n");
    fprintf(dataFile, "%lf pm %lf\n", n, dn);
    fprintf(dataFile, "Distanza dal valore del costruttore: %lf\n\n", getSigma(a, da));
    fprintf(plotFile, "4046.56\t%lf\t%lf\n", a, da);
    getA(violet, violetTheta);
    fprintf(dataFile, "I valori per la lunghezza violetta: \n");
    fprintf(dataFile, "%lf pm %lf A\n", a, da);
    fprintf(dataFile, "Numero di linee nel reticolo: \n");
    fprintf(dataFile, "%lf pm %lf\n", n, dn);
    fprintf(dataFile, "Distanza dal valore del costruttore: %lf\n\n", getSigma(a, da));
    fprintf(plotFile, "4077.81\t%lf\t%lf\n", a, da);
    getA(blue, blueTheta);
    fprintf(dataFile, "I valori per la lunghezza blu: \n");
    fprintf(dataFile, "%lf pm %lf A\n", a, da);
    fprintf(dataFile, "Numero di linee nel reticolo: \n");
    fprintf(dataFile, "%lf pm %lf\n", n, dn);
    fprintf(dataFile, "Distanza dal valore del costruttore: %lf\n\n", getSigma(a, da));
    fprintf(plotFile, "4358.81\t%lf\t%lf\n", a, da);
    getA(darkGreen, darkGreenTheta);
    fprintf(dataFile, "I valori per la lunghezza verde scuro: \n");
    fprintf(dataFile, "%lf pm %lf A\n", a, da);
    fprintf(dataFile, "Numero di linee nel reticolo: \n");
    fprintf(dataFile, "%lf pm %lf\n", n, dn);
    fprintf(dataFile, "Distanza dal valore del costruttore: %lf\n\n", getSigma(a, da));
    fprintf(plotFile, "4916.04\t%lf\t%lf\n", a, da);
    getA(green, greenTheta);
    fprintf(dataFile, "I valori per la lunghezza verde: \n");
    fprintf(dataFile, "%lf pm %lf A\n", a, da);
    fprintf(dataFile, "Numero di linee nel reticolo: \n");
    fprintf(dataFile, "%lf pm %lf\n", n, dn);
    fprintf(dataFile, "Distanza dal valore del costruttore: %lf\n\n", getSigma(a, da));
    fprintf(plotFile, "5460.74\t%lf\t%lf\n", a, da);
    getA(greenYellow, greenYellowTheta);
    fprintf(dataFile, "I valori per la lunghezza verde-gialla: \n");
    fprintf(dataFile, "%lf pm %lf A\n", a, da);
    fprintf(dataFile, "Numero di linee nel reticolo: \n");
    fprintf(dataFile, "%lf pm %lf\n", n, dn);
    fprintf(dataFile, "Distanza dal valore del costruttore: %lf\n\n", getSigma(a, da));
    fprintf(plotFile, "5769.59\t%lf\t%lf\n", a, da);
    getA(yellow, yellowTheta);
    fprintf(dataFile, "I valori per la lunghezza gialla: \n");
    fprintf(dataFile, "%lf pm %lf A\n", a, da);
    fprintf(dataFile, "Numero di linee nel reticolo: \n");
    fprintf(dataFile, "%lf pm %lf\n", n, dn);
    fprintf(dataFile, "Distanza dal valore del costruttore: %lf\n\n", getSigma(a, da));
    fprintf(plotFile, "5790.65\t%lf\t%lf\n", a, da);
    t = t / t1;
    tErr = sqrt(1.0 / tErr);
    fprintf(dataFile, "Media pesata dei valori: \n");
    fprintf(dataFile, "%lf pm %lf\n", t, tErr);
    fclose(valueFile);
    fclose(dataFile);
    fclose(plotFile);
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
    return 0;
}