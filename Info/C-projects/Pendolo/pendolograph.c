#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
    FILE *gnuPlotPipe = NULL;

    char gnuPlotCommand[128];
    snprintf(gnuPlotCommand, sizeof gnuPlotCommand,"plot \"values.dat\" using 1:2:3 with errorbars lc 2 title \"Dati\"");

    gnuPlotPipe = popen("gnuplot -p", "w");

    if(gnuPlotPipe != NULL) {
        // Customization
        fprintf(gnuPlotPipe, "set title \"Periodo in funzione dell'angolo\"\n");
        fprintf(gnuPlotPipe, "set xrange[%f:%f]\n", 0.0011, 0.0112);
        fprintf(gnuPlotPipe, "set key right box\n");
        fprintf(gnuPlotPipe, "set grid\n");
        fprintf(gnuPlotPipe, "set border 3\n");
        fprintf(gnuPlotPipe, "set tics nomirror\n");
        fprintf(gnuPlotPipe, "set ylabel \"h (m)\"\n");
        fprintf(gnuPlotPipe, "set xlabel \"P (N)\"\n");
        //Plotting
        fprintf(gnuPlotPipe, "%s \n", gnuPlotCommand);
        //Quitting
        fprintf(gnuPlotPipe, "quit");
    }  else {
        perror("popen failed");
        return 1;
    }

    pclose(gnuPlotPipe);
    return 0;
}