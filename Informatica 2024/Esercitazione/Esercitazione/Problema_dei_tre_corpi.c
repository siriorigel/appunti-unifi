/*---------------------------------------------------------------------------------------------------------------------------------
Simulazione del problema dei tre corpi.
----------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define G 6.67408e-11
#define DT 86400  // Secondi in un giorno

void Ask_Years(int* years) {
    printf("Inserisci il numero di anni da simulare: ");
    scanf("%d", years);
}

void Ask_Mass(double* m1, double* m2, double* m3) {
    printf("Inserisci la massa del corpo 1 (in kg): ");
    scanf("%lf", m1);
    printf("Inserisci la massa del corpo 2 (in kg): ");
    scanf("%lf", m2);
    printf("Inserisci la massa del corpo 3 (in kg): ");
    scanf("%lf", m3);
}

void Ask_velocity(double *vx1, double *vx2, double *vx3, double *vy1, double *vy2, double *vy3, double *vz1, double *vz2, double *vz3){
    printf("Inserisci la velocità iniziale del corpo 1 suddivisa nelle sue tre componenti: ");
    scanf("%lf %lf %lf", &vx1[0], &vy1[0], &vz1[0]);

    printf("Inserisci la velocità iniziale del corpo 2 suddivisa nelle sue tre componenti: ");
    scanf("%lf %lf %lf", &vx2[0], &vy2[0], &vz2[0]);

    printf("Inserisci la velocità iniziale del corpo 3 suddivisa nelle sue tre componenti: ");
    scanf("%lf %lf %lf", &vx3[0], &vy3[0], &vz3[0]);
}

void Ask_initial_position(double *x1, double *x2, double *x3, double *y1, double *y2, double *y3, double *z1, double *z2, double *z3){
    printf("Inserisci la posizione x, y e z del corpo 1: ");
    scanf("%lf %lf %lf", &x1[0], &y1[0], &z1[0]);

    printf("Inserisci la posizione x, y e z del corpo 2: ");
    scanf("%lf %lf %lf", &x2[0], &y2[0], &z2[0]);

    printf("Inserisci la posizione x, y e z del corpo 3: ");
    scanf("%lf %lf %lf", &x3[0], &y3[0], &z3[0]);
}

void Compute_Acceleration(double m1, double m2, double m3, double r1x, double r1y, double r1z, double r2x, double r2y, double r2z, double r3x, double r3y, double r3z, double* a1x, double* a1y, double* a1z, double* a2x, double* a2y, double* a2z, double* a3x, double* a3y, double* a3z) {
    double r12 = pow(r1x - r2x, 2) + pow(r1y - r2y, 2) + pow(r1z - r2z, 2);
    double r13 = pow(r1x - r3x, 2) + pow(r1y - r3y, 2) + pow(r1z - r3z, 2);
    double r23 = pow(r2x - r3x, 2) + pow(r2y - r3y, 2) + pow(r2z - r3z, 2);

    double r12_3_2 = pow(r12, 1.5);
    double r13_3_2 = pow(r13, 1.5);
    double r23_3_2 = pow(r23, 1.5);

    // Accelerazioni dovute alla gravità
    *a1x = G * ((m2 * (r2x - r1x) / r12_3_2) + (m3 * (r3x - r1x) / r13_3_2));
    *a1y = G * ((m2 * (r2y - r1y) / r12_3_2) + (m3 * (r3y - r1y) / r13_3_2));
    *a1z = G * ((m2 * (r2z - r1z) / r12_3_2) + (m3 * (r3z - r1z) / r13_3_2));

    *a2x = G * ((m1 * (r1x - r2x) / r12_3_2) + (m3 * (r3x - r2x) / r23_3_2));
    *a2y = G * ((m1 * (r1y - r2y) / r12_3_2) + (m3 * (r3y - r2y) / r23_3_2));
    *a2z = G * ((m1 * (r1z - r2z) / r12_3_2) + (m3 * (r3z - r2z) / r23_3_2));

    *a3x = G * ((m1 * (r1x - r3x) / r13_3_2) + (m2 * (r2x - r3x) / r23_3_2));
    *a3y = G * ((m1 * (r1y - r3y) / r13_3_2) + (m2 * (r2y - r3y) / r23_3_2));
    *a3z = G * ((m1 * (r1z - r3z) / r13_3_2) + (m2 * (r2z - r3z) / r23_3_2));
}

void Simulazione(int years, double m1, double m2, double m3, double* x1, double* x2, double* x3, double* y1, double* y2, double* y3, double* z1, double* z2, double* z3, double* vx1, double* vx2, double* vx3, double* vy1, double* vy2, double* vy3, double* vz1, double* vz2, double* vz3) {
    int days = years * 365;

    FILE *file = fopen("Simulation.csv", "w");

    fprintf(file, "day,x1,y1,z1,x2,y2,z2,x3,y3,z3\n");

    for (int day = 0; day < days - 1; day++) {
        double a1x, a1y, a1z, a2x, a2y, a2z, a3x, a3y, a3z;
        Compute_Acceleration(m1, m2, m3, x1[day], y1[day], z1[day], x2[day], y2[day], z2[day], x3[day], y3[day], z3[day], &a1x, &a1y, &a1z, &a2x, &a2y, &a2z, &a3x, &a3y, &a3z);

        // Aggiornamento delle velocità
        vx1[day + 1] = vx1[day] + a1x * DT;
        vy1[day + 1] = vy1[day] + a1y * DT;
        vz1[day + 1] = vz1[day] + a1z * DT;

        vx2[day + 1] = vx2[day] + a2x * DT;
        vy2[day + 1] = vy2[day] + a2y * DT;
        vz2[day + 1] = vz2[day] + a2z * DT;

        vx3[day + 1] = vx3[day] + a3x * DT;
        vy3[day + 1] = vy3[day] + a3y * DT;
        vz3[day + 1] = vz3[day] + a3z * DT;

        // Aggiornamento delle posizioni
        x1[day + 1] = x1[day] + vx1[day] * DT;
        y1[day + 1] = y1[day] + vy1[day] * DT;
        z1[day + 1] = z1[day] + vz1[day] * DT;

        x2[day + 1] = x2[day] + vx2[day] * DT;
        y2[day + 1] = y2[day] + vy2[day] * DT;
        z2[day + 1] = z2[day] + vz2[day] * DT;

        x3[day + 1] = x3[day] + vx3[day] * DT;
        y3[day + 1] = y3[day] + vy3[day] * DT;
        z3[day + 1] = z3[day] + vz3[day] * DT;

        fprintf(file, "%d,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf\n", day, x1[day], y1[day], z1[day], x2[day], y2[day], z2[day], x3[day], y3[day], z3[day]);
    }
            
    fclose(file);

    printf("Il corpo 1 dopo %d anni si trova nella poszione: (%lf, %lf, %lf)\n", years, x1[days-2], y1[days-2], z1[days-2]);
    printf("Il corpo 2 dopo %d anni si trova nella poszione: (%lf, %lf, %lf)\n", years, x2[days-2], y2[days-2], z2[days-2]);
    printf("Il corpo 3 dopo %d anni si trova nella poszione: (%lf, %lf, %lf)\n", years, x3[days-2], y3[days-2], z3[days-2]);

    system("python plot_simulation.py");
}

int main() {
    srand(time(NULL));
    int years;
    Ask_Years(&years);

    double *x1, *x2, *x3, *y1, *y2, *y3, *z1, *z2, *z3;
    double m1, m2, m3;
    Ask_Mass(&m1, &m2, &m3);

    int days = years * 365;
    x1 = (double*)calloc(days, sizeof(double));
    x2 = (double*)calloc(days, sizeof(double));
    x3 = (double*)calloc(days, sizeof(double));

    y1 = (double*)calloc(days, sizeof(double));
    y2 = (double*)calloc(days, sizeof(double));
    y3 = (double*)calloc(days, sizeof(double));

    z1 = (double*)calloc(days, sizeof(double));
    z2 = (double*)calloc(days, sizeof(double));
    z3 = (double*)calloc(days, sizeof(double));

    double *vx1, *vx2, *vx3, *vy1, *vy2, *vy3, *vz1, *vz2, *vz3;
    vx1 = (double*)calloc(days, sizeof(double));
    vx2 = (double*)calloc(days, sizeof(double));
    vx3 = (double*)calloc(days, sizeof(double));
    vy1 = (double*)calloc(days, sizeof(double));
    vy2 = (double*)calloc(days, sizeof(double));
    vy3 = (double*)calloc(days, sizeof(double));
    vz1 = (double*)calloc(days, sizeof(double));
    vz2 = (double*)calloc(days, sizeof(double));
    vz3 = (double*)calloc(days, sizeof(double));

    Ask_velocity(vx1, vx2, vx3, vy1, vy2, vy3, vz1, vz2, vz3);
    Ask_initial_position(x1, x2, x3, y1, y2, y3, z1, z2, z3);

    Simulazione(years, m1, m2, m3, x1, x2, x3, y1, y2, y3, z1, z2, z3, vx1, vx2, vx3, vy1, vy2, vy3, vz1, vz2, vz3);

    free(x1);
    free(x2);
    free(x3);
    free(y1);
    free(y2);
    free(y3);
    free(z1);
    free(z2);
    free(z3);
    free(vx1);
    free(vx2);
    free(vx3);
    free(vy1);
    free(vy2);
    free(vy3);
    free(vz1);
    free(vz2);
    free(vz3);

    return 0;
}
