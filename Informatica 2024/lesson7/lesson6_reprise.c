#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    double x[100], y[100];

    for(int i=1; i<100; i++){
        x[i]=x[i-1]+M_PI/20;
        y[i]=sin(x[i]);
    }

    FILE *fp;
        fp=fopen("data.dat", "w");
        for (int i = 0; i < 100; i++)
        {
            fprintf(fp, "%lf %lf \n", x[i], y[i]);
        }
        fclose(fp);
    
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