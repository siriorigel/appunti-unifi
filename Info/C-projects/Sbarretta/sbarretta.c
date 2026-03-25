#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Valori 
float sigmaE = 15;
float a = 0;
float offset = 0;
float b = 0;
float l = 0;
float PMax = 0;
float *pesi;
float H0 = 0;

//Array per scarto massimo
float *valA;
float *valOff;
float *valB;
float *valL;
float *valH0;
float *valHi;

// ERRORI
float dA = 0.05;
float dB = 0.01;
float dL = 0.5;
float dH0 = 0.02;

void calcolaMedie(FILE *);

void getErrors();

void printData(FILE *);

int main() {
    FILE *esp = fopen("esperienza.dat", "r");
    FILE *dati = fopen("AnalisiEsperienza.dat", "w");
    pesi = (float*)calloc(16, sizeof(float));
    valA = (float*)calloc(16, sizeof(float));
    valOff = (float*)calloc(16, sizeof(float));
    valB = (float*)calloc(16, sizeof(float));
    valL = (float*)calloc(16, sizeof(float));
    valH0 = (float*)calloc(16, sizeof(float));
    valHi = (float*)calloc(16, sizeof(float));
    calcolaMedie(esp);
    PMax = (a * b * b) / l * sigmaE;
    getErrors(esp);
    printData(dati);
    fclose(dati);
    fclose(esp);
    return 0;
}

void calcolaMedie(FILE * file) {
    char line[256];
    int counter = 0;
    int n = 0;
    float avarage = 0;
    while(fgets(line, sizeof(line), file)) {
        if(line[0] == '#') {
            switch(counter) {
                case 3: {
                    a = avarage / (float)n;
                } break;
                case 4: {
                    offset = avarage / (float)n;
                } break;
                case 5: {
                    b = (avarage - offset * n) / (float)n;
                } break;
                case 6: {
                    l = avarage / (float)n;
                } break;
                case 8: {
                    H0 = avarage / (float)n;
                } break;
            }
            avarage = 0;
            n = 0;
            counter++;
        } else {
            switch(counter) {
                case 3: {
                    valA[n] = atof(line);
                } break;
                case 4: {
                    valOff[n] = atof(line);
                } break;
                case 5: {
                    valB[n] = atof(line);
                } break;
                case 6: {
                    valL[n] = atof(line);
                } break;
                case 8: {
                    valH0[n] = atof(line);
                } break;
                case 9: {
                    valHi[n] = atof(line);
                }
            }
            if(counter == 7) {
                pesi[n] = atof(line); 
                n++;
                continue;
            }
            avarage += atof(line);
            n++;
        }
    }
}

void getErrors() {
    // A
    float maxError = 0;
    for(int i = 0; i < 16; i++) {
        if(valA[i] == 0) {
            continue;
        }
        if(fabs(valA[i] - a) > maxError) {
            maxError = fabs(valA[i] - a);
        }
    }
    if(maxError > dA) {
        dA = maxError;
    } 
    maxError = 0;
    // B
        for(int i = 0; i < 16; i++) {
        if(valB[i] == 0) {
            continue;
        }
        if(fabs(valB[i] - b) > maxError) {
            maxError = fabs(valB[i] - b);
        }
    }
    if(maxError > dB) {
        dB = maxError;
    } 
    maxError = 0;
    // L
        for(int i = 0; i < 16; i++) {
        if(valL[i] == 0) {
            continue;
        }
        if(fabs(valL[i] - l) > maxError) {
            maxError = fabs(valL[i] - l);
        }
    }
    if(maxError > dL) {
        dL = maxError;
    } 
    maxError = 0;
    // H0
        for(int i = 0; i < 16; i++) {
        if(valH0[i] == 0) {
            continue;
        }
        if(fabs(valH0[i] - H0) > maxError) {
            maxError = fabs(valH0[i] - H0);
        }
    }
    if(maxError > dH0) {
        dH0 = maxError;
    } 
    maxError = 0;
}

void printData(FILE *file) {
    fprintf(file, "Analisi Dati (TUTTO IN MILLIMETRI): \n\n");
    fprintf(file, "Larghezza sbarretta (a): %f +- %f\n", a, dA);
    fprintf(file, "Offset palmer: %f\n", offset);
    fprintf(file, "Spessore sbarretta (b): %f +- %f\n", b, dB);
    fprintf(file, "Lunghezza barretta sui cavalieri (l): %f +- %f\n", l, dL);
    fprintf(file, "Valore di H0: %f +- %f\n", H0, dH0);
    fprintf(file, "Pesi in uso con valore di c: \n\n");
    float cAv = 0;
    int n = 0;
    for(int i = 0; i < 16; i++) {
        if(pesi[i] == 0) {
            continue;
        }
        float c = (H0 - valHi[i]) / (pesi[i]);
        cAv += c;
        n++;
        fprintf(file, "%f kg, altezza %f mm, valore di c %f mm / Kg\n", pesi[i], valHi[i], c);
    }
    fprintf(file, "Valore medio di c %f", cAv / n);
}