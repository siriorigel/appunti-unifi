#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double bins = 9;

typedef struct{
    double xMin;
    double xCenter;
    double xMax;
    double Nk;
    double Fk;
    double fk;
    double sigmafk;
    double fGauss;
} bin;

int fileSize(FILE* file, int excludedIndex);

double getSigma(FILE* file, int excludedIndex);

double getAvarage(FILE* file, int excludedIndex);

double getTForValue(double value);

void chauvenetElimination(FILE* file, FILE* data, int doubleElimination);

double getNk(FILE* file, double start, double finish, int excluded);

void getBins(FILE* file, int excluded, FILE* binF, FILE* data);

double xMin = 0;
double xMax = 0;
double sigma = 0;
double avarage = 0;
int elements = 0;
bin binData[9] = {};

int main() {

    // File to generate functions
    char* functionPoints = "values.dat";

    // File where other data is saved
    char* dataFile  = "dataFile.dat";

    // Bin Data
    char* binFile = "binData.dat";

    // Defining all the files
    FILE* functionP = fopen(functionPoints, "r");
    FILE* dataF = fopen(dataFile, "w");
    FILE* binF = fopen(binFile, "w");
    FILE* gnuPlotPipe = NULL;
    
    if(functionP == NULL){
        printf("File is unreadable or missing!");
        return 1;
    }

    elements = fileSize(functionP, -1);
    avarage = getAvarage(functionP, -1);
    sigma = getSigma(functionP, -1);
    fprintf(dataF, "Before Chauvenet \n");
    fprintf(dataF, "Avarage: %f\n", avarage);
    fprintf(dataF, "Elements: %d\n", elements);
    fprintf(dataF, "Sigma: %f\n", sigma);
    fprintf(dataF, "Max value: %f\n", xMax);
    fprintf(dataF, "Min value: %f\n\n", xMin);

    chauvenetElimination(functionP, dataF, 1);

    fprintf(dataF, "After Chauvenet \n");
    fprintf(dataF, "Avarage: %f\n", avarage);
    fprintf(dataF, "Elements: %d\n", elements);
    fprintf(dataF, "Sigma: %f\n", sigma);
    fprintf(dataF, "Max value: %f\n", xMax);
    fprintf(dataF, "Min value: %f\n\n", xMin);

    getBins(functionP, -1, binF, dataF);
    fclose(binF);
    binF = fopen(binFile, "r");

    char gnuPlotCommand[512];
    snprintf(gnuPlotCommand, sizeof gnuPlotCommand,"plot \"binData.dat\" using 1:2:3 with errorbars lc 3 title \"Istogramma\", \"binData.dat\" using 1:2 with boxes lc 3 notitle , ((1)/(%f * sqrt(2*pi))) * exp(-(x - %f)**(2)/(2 * %f**2)) lc 1 title \"Modello\"", sigma, avarage, sigma);

    gnuPlotPipe = popen("gnuplot -p", "w");
    fclose(dataF);
    fclose(functionP);
    fclose(binF);

    if(gnuPlotPipe != NULL) {
        //Settings
        fprintf(gnuPlotPipe, "set title \"Distribuzione con %d bin \"\n", (int)bins);
        fprintf(gnuPlotPipe, "set xrange [%f:%f]\n", xMin, xMax);
        fprintf(gnuPlotPipe, "set key top right box\n");
        fprintf(gnuPlotPipe, "set grid\n");
        fprintf(gnuPlotPipe, "set border 3\n");
        fprintf(gnuPlotPipe, "set tics nomirror\n");
        fprintf(gnuPlotPipe, "set ylabel \"fk valori\"\n");

        //Plotting
        fprintf(gnuPlotPipe, "%s \n", gnuPlotCommand);

        //Bye bye
        fprintf(gnuPlotPipe, "quit");

    } else {
        perror("popen failed");
        return 1;
    }

    return 0;
}

double getSigma(FILE* file, int excludedIndex) {
    char line[256];
    double sigma = 0;
    double allDifferences = 0;
    int counter = 0;
    while(fgets(line, sizeof(line), file)) {
        if(counter == excludedIndex) {
            counter++;
            continue;
        }
        counter++;
        double number = atof(line);
        allDifferences += pow((number - avarage), 2.0);
    }
    sigma = sqrt((1.0) / (elements - 1.0) * allDifferences); 
    fseek(file, 0, SEEK_SET);
    return sigma;
}

double getAvarage(FILE* file, int excludedIndex) {
    char line[256];
    double number = 0;
    int counter = 0;
    double total = 0;
    fgets(line, sizeof(line), file);
    if(line != NULL) {
        if(counter != excludedIndex) {
            xMin = atof(line);
            total += xMin;
        }
        counter++;
    }
    fgets(line, sizeof(line), file);
    if(line != NULL) {
        if(counter != excludedIndex) {
            xMax = atof(line);
            total += xMax;
        }
        counter++;
    }
    while (fgets(line, sizeof(line), file)) {
        if(counter == excludedIndex) {
            counter++;
            continue;
        }
        number = atof(line);
        if(xMin < number) {
            if(xMax <= number) {
                xMax = number;
            }
        } else {
            xMin = number;
        }
        total += number;
        counter++;
    }
    fseek(file, 0, SEEK_SET);
    return total / elements;
}

int fileSize(FILE* file, int excludedIndex){
    char line[256];
    int counter = 0;
    while (fgets(line, sizeof(line), file)) {
        counter++;
    }
    if(excludedIndex != -1) {
        counter--;
    }
    fseek(file, 0, SEEK_SET);
    return counter;
}

double getTForValue(double value) {
    double val = fabs(value - avarage) / sigma;
    return val;
}

void chauvenetElimination(FILE* file, FILE* data, int doubleElimination) {
    char line[256];
    int counter = 0;
    int arrayCounter = 0;
    int excludedIndex = -1;
    double possibleTs[elements];
    while (fgets(line, sizeof(line), file)) {
        double t = getTForValue(atof(line));
        possibleTs[counter] = t;
        counter++;
    }
    double maxT = 0;
    for(int i = 0; i < elements; i++) {
        if(i == 0) {
            maxT = possibleTs[i];
            excludedIndex = i;
        }
        if(possibleTs[i] >= maxT) {
            maxT = possibleTs[i];
            excludedIndex = i;
        }
    }
    if(maxT >= 2 ) {
        int row = excludedIndex + 1;
        fprintf(data, "Value to be eliminated at row %d\nDistance from avarage: %f sigma\n", row, maxT);
        fseek(file, 0, SEEK_SET);
        elements = fileSize(file, excludedIndex);
        avarage = getAvarage(file, excludedIndex);
        sigma = getSigma(file, excludedIndex);
    }
    fseek(file, 0, SEEK_SET);
}

double getNk(FILE * file, double start, double finish, int excluded) {
    fseek(file, 0, SEEK_SET);
    char line[256];
    double number = 0;
    int counter = 0;
    int Nk = 0;
    while(fgets(line, sizeof(line), file)) {
        number = atof(line);
        if(number >= start && number <= finish) {
            if(counter != excluded) {
                Nk++;
            }
        }
        counter++;
    }
    return Nk;
}

void getBins(FILE* file, int excluded, FILE* binF, FILE* data) {
    double step = (fabs(xMax - xMin)) / (bins);
    double start = xMin;
    double finish = start + step;
    fprintf(binF, "#Center fk sigmafk\n");
    for(int i = 0; i < bins; i++) {
        bin newbin;
        newbin.xMin = start;
        newbin.xMax = finish;
        newbin.xCenter = start + step / 2.0;
        double Nk = getNk(file, start, finish, excluded);
        newbin.Nk = Nk;
        double Fk = Nk / elements;
        newbin.Fk = Fk;
        newbin.fk = Fk / step;
        newbin.sigmafk = (sqrt(Nk) / (step * elements));
        newbin.fGauss = ((1.0)/(sigma * sqrt(2.0 * 3.1415))) * pow(2.71,-pow((step / 2.0) -avarage, 2.0)/(2.0 * pow(sigma, 2.0)));
        binData[i] = newbin;
        start = finish;
        finish = start + step;
        fprintf(data, "Bin Data: \n");
        fprintf(data, "Bin %d\n", i);
        fprintf(data, "Interval: %f  -  %f\n", newbin.xMin, newbin.xMax);
        fprintf(data, "Center: %f\n", newbin.xCenter);
        fprintf(data, "Nk: %f\n", Nk);
        fprintf(data, "Fk: %f\n", Fk);
        fprintf(data, "fk: %f\n", newbin.fk);
        fprintf(data, "sigmafk: %f\n", newbin.sigmafk);
        fprintf(data, "fGauss: %f\n\n", newbin.fGauss);
        fprintf(binF, "%f %f %f\n", newbin.xCenter, newbin.fk, newbin.sigmafk);
    }
}