#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct line line;

struct line{
    double A;
    double B;
};

int getElements(FILE* values);

double getXMin(FILE* values);

double getXMax(FILE* values);

double getX(FILE* values, int row);

double getY(FILE* values, int row);

double getError(FILE* values, int row);

int insideErrorBar(double x, double yCal, double trueY, double yError);

int getBestError(double errors[]);

int isCrescent(double y[], int invalid[]);

void getRBest (FILE* values, int invalid[]);

double linearCoefficient(FILE* values, int invalid[]);

double getSigmaY(FILE* values);

double getSigmaA(FILE* values);

double getSigmaB(FILE* values);

void getQuality(double val);

void checkForInvalid(FILE* values, FILE* data);

double xMax = 0;
double xMin = 0;
double yMax = 0;
double yMIn = 0;

int elements = 0;

struct line rBest;

double sigmaA = 0;
double sigmaB = 0;
double sigmaY = 0;
double coefficient = 0;

char quality[16];

int main() {

    char *values = "values.dat";
    char *data = "data.dat";

    FILE *valueFile = fopen(values, "r");
    FILE *dataFile  = fopen(data, "w");
    FILE* gnuPlotPipe = NULL;
    
    if(valueFile == NULL){
        printf("File is unreadable or missing!");
        return 1;
    }

    elements = getElements(valueFile);
    xMin = getXMin(valueFile);
    xMax = getXMax(valueFile);
    int inval[elements]; 
    for(int i = 0; i < elements; i++) {
        inval[i] = 0; 
    }
    sigmaY = getSigmaY(valueFile);
    sigmaA = getSigmaA(valueFile);
    sigmaB = getSigmaB(valueFile);

    fprintf(dataFile, "Linear fit with data from \"values.dat\"\n");
    checkForInvalid(valueFile, dataFile);
    fprintf(dataFile, "RBEST:\n");
    fprintf(dataFile, "y = %f + %fx\n", rBest.A, rBest.B);
    fprintf(dataFile, "A best = %f\n", rBest.A);
    fprintf(dataFile, "B best = %f\n\n", rBest.B);
    getQuality(coefficient);
    fprintf(dataFile, "Linear coefficient = %f\n", coefficient);
    fprintf(dataFile, "The quality of the model is %s\n\n", quality);
    fprintf(dataFile, "Sigmas: \n");
    fprintf(dataFile, "Sigma on y: %f\n", sigmaY);
    fprintf(dataFile, "Sigma on A: %f\n", sigmaA);
    fprintf(dataFile, "Sigma on B: %f\n\n", sigmaB);
    fprintf(dataFile, "Actual values of A and B in the linear model: \n");

    char gnuPlotCommand[512];
    snprintf(gnuPlotCommand, sizeof gnuPlotCommand, "plot \"values.dat\" using 1:2:3 with errorbars lc 3 title \"Dati\"");

    gnuPlotPipe = popen("gnuplot -p", "w");
    fclose(valueFile);
    fclose(dataFile);

    if(gnuPlotPipe != NULL) {
        // Customization
        fprintf(gnuPlotPipe, "set title \"Fit lineare\"\n");
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

    return 0;
}

int getElements(FILE* values) {
    char line[256] = "";
    int counter = 0;
    while(fgets(line, sizeof(line), values)) {
        counter++;
    }
    fseek(values, 0, SEEK_SET);
    return counter;
}

double getXMin(FILE* values) {
    char line[256] = "";
    fgets(line, sizeof(line), values);
    double value = atof(line);
    fseek(values, 0, SEEK_SET);
    return value - (value / 100.0) * 20.0;
}

double getXMax(FILE* values) {
    char line[256] = "";
    double value  = 0;
    while(fgets(line, sizeof(line), values)) {}
    value = atof(line);
    fseek(values, 0, SEEK_SET);
    return value + (value / 100.0) * 20.0;
}

double getX(FILE* values, int row) {
    char line[256] = "";
    double value = 0;
    double counter = 0;
    fseek(values, 0, SEEK_SET);
    while(fgets(line, sizeof(line), values)) {
        counter++;
        if(counter == row) {
            value = atof(line);
            break;
        }
    }
    fseek(values, 0, SEEK_SET);
    return value;
}

double getY(FILE* values, int row) {
    char line[256] = "";
    char yLine[256] = "";
    char space = ' ';
    double value = 0;
    double counter = 0;
    int yLineCounter = 0;
    fseek(values, 0, SEEK_SET);
    while(fgets(line, sizeof(line), values)) {
        counter++;
        if(counter == row) {
            int encountered = 0;
            for(int i = 0; i < 256; i++) {
                if(line[i] == space) {
                    if(encountered == 0) {
                        encountered++;
                        continue;
                    } else {
                        break;
                    }
                }
                if(encountered > 0) {
                    yLine[yLineCounter] = line[i];
                    yLineCounter++;
                }
            }
            value = atof(yLine);
            break;
        }
    }
    fseek(values, 0, SEEK_SET);
    return value;
}

double getError(FILE* values, int row) {
    char line[256] = "";
    char yLine[256] = "";
    char space = ' ';
    char null ='\0';
    double value = 0;
    double counter = 0;
    int yLineCounter = 0;
    fseek(values, 0, SEEK_SET);
    while(fgets(line, sizeof(line), values)) {
        counter++;
        if(counter == row) {
            int encountered = 0;
            for(int i = 0; i < 256; i++) {
                if(line[i] == space) {
                    encountered++;
                }
                if(encountered > 1) {
                    yLine[yLineCounter] = line[i];
                    yLineCounter++;
                }
                if(line[i] == null) {
                    break;
                }
            }
            value = atof(yLine);
            break;
        }
    }
    fseek(values, 0, SEEK_SET);
    return value;
}

int insideErrorBar(double x, double yCal, double trueY, double yError) {
    if((trueY + yError) >= (yCal) && (trueY - yError ) <= (yCal)) {
        return 1;
    }
    return 0;
}

int getBestError(double errors[]) {
    int best = 0;
    for(int i = 0; i < elements; i++) {
        if(fabs(errors[i]) <= fabs(errors[best])) {
            best = i;
        }
    }
    return best;
}

int isCrescent(double y[], int invalid[]) {
    int crescent = 0;
    if(invalid[0] != 1 && invalid[elements - 1] != 0) {
        if(y[0] >= y[elements - 1]) {
            crescent = 0;
        } else {
            crescent = 1;
        }
        return crescent;
    } else {
        int c = 0;
        int d = 0;
        for(int i = 0; i < elements - 1; i ++) {
            if(invalid[i] != 1) {
                if(y[i] >= y[i + 1]) {
                    c++;
                } else {
                    d++;
                }
            }
        }
        if(c >= d) {
            return 1;
        } else{
            return 0;
        }
    }
}

void getRBest(FILE* values, int invalid[]) {
    char line[256] = "";
    double x[elements];
    double y[elements];
    double errors[elements];
    for(int i = 0; i < elements; i++) {
        x[i] = getX(values, i + 1);
        y[i] = getY(values, i + 1);
        errors[i] = getError(values, i + 1);
    }
    int bestIndex = getBestError(errors);
    double bestX = x[bestIndex];
    double bestY = y[bestIndex];
    double bestError = errors[bestIndex];
    double num1 = 0;
    double num2P1 = 0;
    double num2P2 = 0;
    double demP1 = 0;
    double demP2 = 0;
    double xSum = 0;
    double ySum = 0;
    double xySum = 0;
    for(int i = 0; i < elements; i++) {
        num1 += pow(x[i], 2);
        xySum += x[i] * y[i];
        xSum += x[i];
        ySum += y[i];
        demP1 += pow(x[i], 2);
        demP2 += x[i];
    }
    num1 *= ySum;
    num1 += -(xSum * xySum);
    num2P1 += xySum;
    num2P2 += xSum * ySum;
    rBest.A = num1 / (((double)elements * demP1)  - pow(demP2, 2));
    rBest.B = (((double)elements * num2P1) - num2P2) / (((double)elements * demP1)  - pow(demP2, 2));
}

double linearCoefficient(FILE* values, int invalid[]) {
    char line[256] = "";
    double xAvarage = 0;
    double yAvarage = 0;
    int counter = 0;
    for(int i = 0; i < elements; i++) {
        if(invalid[i] == 1) {
            counter++;
            continue;
        }
        xAvarage += getX(values, i + 1);
        yAvarage += getY(values, i + 1);
        counter++;
    }
    xAvarage /= (double)counter;
    yAvarage /= (double)counter;
    double numerator = 0;
    double denominator = 0;
    double sqrSum = 0;
    for(int i = 0; i < elements; i++) {
        if(invalid[i] == 1) {
            continue;
        }
        numerator += pow(getX(values, i + 1) - xAvarage, 2) * pow(getY(values, i + 1) - yAvarage, 2);
        sqrSum += pow(getX(values, i + 1) - xAvarage, 2);
        denominator += pow(getY(values, i + 1) - yAvarage, 2);
    }
    denominator += sqrt(sqrSum);
    return (numerator / denominator);
}

double getSigmaY(FILE* values) {
    double sum = 0;
    for(int i = 0; i < elements; i++) {
        sum+=pow(getY(values, i + 1) - rBest.A - rBest.B * getX(values, i + 1), 2);
    }
    return sqrt(sum / (double)(elements - 2));
}

double getSigmaA(FILE* values) {
    double numerator = 0;
    double denominator1 = 0;
    double denominator2 = 0;
    double denominator = 0;
    for(int i = 0; i < elements; i++) {
        numerator += pow(getX(values, i + 1), 2);
        denominator1 += pow(getX(values, i + 1), 2);
        denominator2 += getX(values, i + 1);
    }
    denominator1 *= elements;
    denominator2 = pow(denominator2, 2);
    denominator = denominator1 - denominator2;
    return sigmaY * sqrt(numerator / denominator);
}

double getSigmaB(FILE* values) {
    double denominator1 = 0;
    double denominator2 = 0;
    double denominator = 0;
    for(int i = 0; i < elements; i++) {
        denominator1 += pow(getX(values, i + 1), 2);
        denominator2 += getX(values, i + 1);
    }
    denominator1 *= elements;
    denominator2 = pow(denominator2, 2);
    denominator = denominator1 - denominator2;
    return sigmaY * sqrt(elements / denominator);
}

void getQuality(double val) {
    if(val > 0.8) {
        snprintf(quality, sizeof(quality), "linear");
    } else {
        if(val < 0.2) {
            snprintf(quality, sizeof(quality), "absurd");
        } else {
            if(val >= 0.2 && val < 0.4) {
                snprintf(quality, sizeof(quality), "not linear");
            } else if(val > 0.6 && val <= 0.8) {
                snprintf(quality, sizeof(quality), "almost linear");
            } else {
                snprintf(quality, sizeof(quality), "not so linear");
            }
        }
    }
}

void checkForInvalid(FILE* values, FILE* data) {
    char line[256] = "";
    double value = 0;
    double x[elements];
    double y[elements];
    double errors[elements];
    int invalids[elements];
    for(int i = 0; i < elements; i++) {
        x[i] = getX(values, i + 1);
        y[i] = getY(values, i + 1);
        errors[i] = getError(values, i + 1);
    }
    fprintf(data, "Values to be removed at row :\n");
    for(int i = 0; i < elements; i++) {
        if(fabs((rBest.A + rBest.B * x[i]) - y[i]) / sigmaY >= 2) {
            invalids[i] = 1;
            fprintf(data, "%d \n", i + 1);
        } else {
            invalids[i] = 0; 
        }
    }
    getRBest(values, invalids);
    coefficient = linearCoefficient(values, invalids);
}