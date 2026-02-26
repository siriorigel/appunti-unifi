#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double focals[4] = {14.70104094, 14.72829588, 14.72108907, 14.74797106};
double errFocals[4] = {0.09, 0.09, 0.1, 0.04};

double focal = 0.0;
double errFocal = 0.0;

int main() {
    FILE* gnuPlotPipe = NULL;
    
    char gnuPlotCommand[512];
    snprintf(gnuPlotCommand, sizeof gnuPlotCommand, "plot \"values.dat\" using 1:2:3 with errorbars lc 7 pt 14 notitle, \"values.dat\" using 1:2 with points pointtype 7 pointsize 1 lc 7 notitle");

    gnuPlotPipe = popen("gnuplot -p", "w");

    if(gnuPlotPipe != NULL) {
        // Customization
        fprintf(gnuPlotPipe, "set title \"Lunghezze focali per sperimentatore\"\n");
        fprintf(gnuPlotPipe, "set xrange[0:5]\n");
        fprintf(gnuPlotPipe, "set border 3\n");
        fprintf(gnuPlotPipe, "set tics nomirror\n");
        fprintf(gnuPlotPipe, "set ylabel \"f (cm)\"\n");
        fprintf(gnuPlotPipe, "set xlabel \"sperimentatore\"\n");
        //Plotting
        fprintf(gnuPlotPipe, "%s \n", gnuPlotCommand);
        //Quitting
        fprintf(gnuPlotPipe, "quit");
    }  else {
        perror("popen failed");
        return 1;
    }

    double tot = 0.0;
    double totM = 0.0;
    for (int i = 0; i < 4; i++) {
        focal += focals[i] * errFocals[i];
        tot += errFocals[i];
        totM += (1.0 / (errFocals[i] * errFocals[i]));
    }
    focal /= tot;
    errFocal = sqrt(1.0 / totM);
    printf("%f\n", focal);
    printf("%f\n", errFocal);
    return 0;
}