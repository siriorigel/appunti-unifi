#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double Calcolo_media(int n, double *x){
    double media = 0.0;  // Inizializzare la variabile media

    for (int i = 0; i < n; i++) {
        media += x[i];
    }
    media = media / n;

    return media;
}

void Ask_Particle_Lato(int *n, int* lato){
    do {
        printf("Inserisci il numero di particelle: ");
        scanf("%d", n);

        if (*n <= 0) {
            printf("Il numero di particelle deve essere maggiore di 0.\n");
        }

    } while (*n <= 0);  // Utilizzare il valore puntato da n

    do {
        printf("Inserisci il lato della superficie: ");
        scanf("%d", lato);
        if (*lato <= 0) {
            printf("Il lato deve essere maggiore di 0.\n");
        }

    } while (*lato <= 0);  // Utilizzare il valore puntato da lato
}

void genera_coordinate(int n, int lato, double *coordinate_x, double *coordinate_y){
    for (int i = 0; i < n; i++) {
        coordinate_x[i] = ((double)rand() / (double)RAND_MAX) * lato;
        coordinate_y[i] = ((double)rand() / (double)RAND_MAX) * lato;
    }
}

void calcola_centro_massa(int n, double *coordinate_x, double *coordinate_y, double **centro_massa){
    double media_x = Calcolo_media(n, coordinate_x);
    double media_y = Calcolo_media(n, coordinate_y);

    centro_massa[0][0] = media_x;
    centro_massa[0][1] = media_y;

    printf("Centro massa: (%.2lf, %.2lf)\n", media_x, media_y); 
}

void Write_File(int n, double *coordinate_x, double *coordinate_y, double **centro_massa){
    FILE *file = fopen("coordinate_particelle.dat", "w");
    if (file == NULL) {
        printf("Errore nella creazione del file.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(file, "%.2lf %.2lf\n", coordinate_x[i], coordinate_y[i]);
    }

    fclose(file);
    printf("File coordinate_particelle.dat creato con successo.\n");

    FILE *file_centro_massa = fopen("centro_massa.dat", "w");
    if (file_centro_massa == NULL) {
        printf("Errore nella creazione del file.\n");
        return;
    }

    fprintf(file_centro_massa, "%.2lf %.2lf\n", centro_massa[0][0], centro_massa[0][1]);

    fclose(file_centro_massa);
    printf("File centro_massa.dat creato con successo.\n");
}

void Write_Gnuplot(int n, double *coordinate_x, double *coordinate_y){
        system("gnuplot Grafico.gp");
    }

int main(){
    srand(time(NULL));

    int n, lato;
    double *coordinate_x, *coordinate_y;
    double **centro_massa;  // Puntatore alla matrice centro di massa

    Ask_Particle_Lato(&n, &lato);

    coordinate_x = malloc(n * sizeof(double));
    coordinate_y = malloc(n * sizeof(double));

    if (coordinate_x == NULL || coordinate_y == NULL) {
        printf("Errore nell'allocazione della memoria.\n");
        return 1;
    }

    // Allocazione dinamica per la matrice centro_massa
    centro_massa = malloc(1 * sizeof(double*));
    centro_massa[0] = malloc(2 * sizeof(double));

    if (centro_massa == NULL || centro_massa[0] == NULL) {
        printf("Errore nell'allocazione della memoria per il centro di massa.\n");
        free(coordinate_x);
        free(coordinate_y);
        return 1;
    }

    genera_coordinate(n, lato, coordinate_x, coordinate_y);
    calcola_centro_massa(n, coordinate_x, coordinate_y, centro_massa);
    Write_File(n, coordinate_x, coordinate_y, centro_massa);
    Write_Gnuplot(n, coordinate_x, coordinate_y);


    // Liberare la memoria allocata
    free(coordinate_x);
    free(coordinate_y);
    free(centro_massa[0]);
    free(centro_massa);

    return 0;
}
