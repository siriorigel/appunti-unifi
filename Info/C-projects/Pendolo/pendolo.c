#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

float calcPeriod(float, float, FILE*);

float calcPhi(float, float, float, float, FILE*);

float findTphi0(FILE *, FILE*);

float DeltaT;
float dPhi;

// Pipps
int main(void) {
    char *data = "data.dat";
    char *periodo = "periodo.dat";
    FILE *dataF = fopen(data, "w");
    FILE *periodoF = fopen(periodo, "r");
    float x0;
    float l;
    float dx0;
    float dl;
    float phi0;
    float T0;
    printf("Immettere i dati per trovare phi\n");
    printf("Mettere x0: ");
    scanf("%f", &x0);
    printf("Immettere la lunghezza l: ");
    scanf("%f", &l);
    printf("Immettere l'errore sulla scala x0: ");
    scanf("%f", &dx0);
    printf("Immettere l'errore già sommato dL: ");
    scanf(" %f", &dl);
    phi0 = calcPhi(x0, l, dx0, dl, dataF);
    T0 = calcPeriod(findTphi0(periodoF, dataF), phi0, dataF);
    fclose(dataF);
    fclose(periodoF);
}

//Calculates phi and its error
float calcPhi(float x0, float l, float dx0, float dl, FILE *thisF) {
    float phi = asin(x0 / l);
    dPhi = ((x0) / sqrt(l * l - x0 * x0)) * ((dx0 / x0) + (dl / l));
    fprintf(thisF, "Angolo e sua incertezza\n");
    fprintf(thisF, "%f ± %f\n", phi, dPhi);
    return phi;
}

float calcPeriod(float Tphi0, float phi0,FILE *thisF) {
    float T0 = (Tphi0) / (1.0 + (1.0 / 4.0) * sin(phi0 / 2.0) * sin(phi0 / 2.0));
    float DeltaT0 = T0 * ((DeltaT / Tphi0) + (1.0/ 8.0) * ((sin(phi0)) /(1.0 + (1.0 / 4.0) * sin(phi0 / 2.0) * sin(phi0 / 2.0))) * dPhi);
    fprintf(thisF, "Periodo effettivo e sua incertezza\n");
    fprintf(thisF, "%f ± %f\n", T0, DeltaT0);
    return T0;
}

float findTphi0(FILE *periodoF, FILE *data) {
    char line[256] = "";
    char p = '#';
    int counter = 0;
    int firstC = 0;
    float av = 0;
    int n = 0;
    float err = 0;
    while(fgets(line, sizeof(line), periodoF)){
        if(line[0] == p) {
            if(counter == 0) {
                continue;
            }
            if(firstC == 0) {
                firstC = 1;
                continue;       
            }
        }
        if(firstC == 0) {
            if (counter == 1) {
                n = atoi(line);
                continue;
            }
            av = atof(line);
            counter++;
        } else {
            err = atof(line);
        }
    }
    av /= n;
    DeltaT = err / n;
    fprintf(data, "Valore vero periodo(misurato) e sua incertezza \n");
    fprintf(data, "%f ± %f\n", av, DeltaT);
    fseek(periodoF, 0, SEEK_SET);
    return av;
}