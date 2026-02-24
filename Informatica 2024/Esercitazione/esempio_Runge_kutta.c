#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67408e-11

// Funzione per calcolare l'accelerazione di un corpo
void acceleration(double *r1, double *r2, double *r3, double m1, double m2, double m3, double *a1, double *a2, double *a3) {
    double r12 = sqrt(pow(r1[0] - r2[0], 2) + pow(r1[1] - r2[1], 2) + pow(r1[2] - r2[2], 2));
    double r13 = sqrt(pow(r1[0] - r3[0], 2) + pow(r1[1] - r3[1], 2) + pow(r1[2] - r3[2], 2));
    double r23 = sqrt(pow(r2[0] - r3[0], 2) + pow(r2[1] - r3[1], 2) + pow(r2[2] - r3[2], 2));

    a1[0] = G * (m2 * (r2[0] - r1[0]) / pow(r12, 3) + m3 * (r3[0] - r1[0]) / pow(r13, 3));
    a1[1] = G * (m2 * (r2[1] - r1[1]) / pow(r12, 3) + m3 * (r3[1] - r1[1]) / pow(r13, 3));
    a1[2] = G * (m2 * (r2[2] - r1[2]) / pow(r12, 3) + m3 * (r3[2] - r1[2]) / pow(r13, 3));

    a2[0] = G * (m1 * (r1[0] - r2[0]) / pow(r12, 3) + m3 * (r3[0] - r2[0]) / pow(r23, 3));
    a2[1] = G * (m1 * (r1[1] - r2[1]) / pow(r12, 3) + m3 * (r3[1] - r2[1]) / pow(r23, 3));
    a2[2] = G * (m1 * (r1[2] - r2[2]) / pow(r12, 3) + m3 * (r3[2] - r2[2]) / pow(r23, 3));

    a3[0] = G * (m1 * (r1[0] - r3[0]) / pow(r13, 3) + m2 * (r2[0] - r3[0]) / pow(r23, 3));
    a3[1] = G * (m1 * (r1[1] - r3[1]) / pow(r13, 3) + m2 * (r2[1] - r3[1]) / pow(r23, 3));
    a3[2] = G * (m1 * (r1[2] - r3[2]) / pow(r13, 3) + m2 * (r2[2] - r3[2]) / pow(r23, 3));
}

// Funzione per eseguire un passo di simulazione con il metodo Runge-Kutta di quarto ordine
void step(double *r1, double *v1, double *r2, double *v2, double *r3, double *v3, double m1, double m2, double m3, double dt) {
    double a1[3], a2[3], a3[3], a4[3], k1[3], k2[3], k3[3], k4[3];

    // Calcolo delle accelerazioni
    acceleration(r1, r2, r3, m1, m2, m3, a1, a2, a3);

    // Calcolo di k1
    k1[0] = dt * v1[0];
    k1[1] = dt * v1[1];
    k1[2] = dt * v1[2];

    k1[0] += dt * a1[0];
    k1[1] += dt * a1[1];
    k1[2] += dt * a1[2];

    k2[0] = dt * (v1[0] + k1[0] / 2);
    k2[1] = dt * (v1[1] + k1[1] / 2);
    k2[2] = dt * (v1[2] + k1[2] / 2);

    acceleration(r1 + k1[0], r2 + k1[1], r3 + k1[2], m1, m2, m3, a2, a2, a3);

    k2[0] += dt * a2[0];
    k2[1] += dt * a2[1];
    k2[2] += dt * a2[2];

    k3[0] = dt * (v1[0] + k2[0] / 2);
    k3[1] = dt * (v1[1] + k2[1] / 2);
    k3[2] = dt * (v1[2] + k2[2] / 2);

    acceleration(r1 + k2[0], r2 + k2[1], r3 + k2[2], m1, m2, m3, a2, a2, a3);

    k3[0] += dt * a3[0];
    k3[1] += dt * a3[1];
    k3[2] += dt * a3[2];

    k4[0] = dt * (v1[0] + k3[0]);
    k4[1] = dt * (v1[1] + k3[1]);
    k4[2] = dt * (v1[2] + k3[2]);

    acceleration(r1 + k3[0], r2 + k3[1], r3 + k3[2], m1, m2, m3, a4, a4, a4);

    k4[0] += dt * a4[0];
    k4[1] += dt * a4[1];
    k4[2] += dt * a4[2];

    // Aggiornamento delle posizioni e delle velocità
    r1[0] += (k1[0] + 2 * k2[0] + 2 * k3[0] + k4[0]) / 6;
    r1[1] += (k1[1] + 2 * k2[1] + 2 * k3[1] + k4[1]) / 6;
    r1[2] += (k1[2] + 2 * k2[2] + 2 * k3[2] + k4[2]) / 6;

    v1[0] += (k1[0] + 2 * k2[0] + 2 * k3[0] + k4[0]) / 6;
    v1[1] += (k1[1] + 2 * k2[1] + 2 * k3[1] + k4[1]) / 6;
    v1[2] += (k1[2] + 2 * k2[2] + 2 * k3[2] + k4[2]) / 6;

    r2[0] += (k1[0] + 2 * k2[0] + 2 * k3[0] + k4[0]) / 6;
    r2[1] += (k1[1] + 2 * k2[1] + 2 * k3[1] + k4[1]) / 6;
    r2[2] += (k1[2] + 2 * k2[2] + 2 * k3[2] + k4[2]) / 6;

    v2[0] += (k1[0] + 2 * k2[0] + 2 * k3[0] + k4[0]) / 6;
    v2[1] += (k1[1] + 2 * k2[1] + 2 * k3[1] + k4[1]) / 6;
    v2[2] += (k1[2] + 2 * k2[2] + 2 * k3[2] + k4[2]) / 6;

    r3[0] += (k1[0] + 2 * k2[0] + 2 * k3[0] + k4[0]) / 6;
    r3[1] += (k1[1] + 2 * k2[1] + 2 * k3[1] + k4[1]) / 6;
    r3[2] += (k1[2] + 2 * k2[2] + 2 * k3[2] + k4[2]) / 6;

    v3[0] += (k1[0] + 2 * k2[0] + 2 * k3[0] + k4[0]) / 6;
    v3[1] += (k1[1] + 2 * k2[1] + 2 * k3[1] + k4[1]) / 6;
    v3[2] += (k1[2] + 2 * k2[2] + 2 * k3[2] + k4[2]) / 6;
}

int main() {
    // Parametri di simulazione
    int years = 100;
    double dt = 0.01;

    // Masse dei corpi
    double m1 = 1.0, m2 = 0.5, m3 = 0.25;

    // Posizioni e velocità iniziali dei corpi
    double r1[3] = {1.0, 0.0, 0.0};
    double v1[3] = {0.0, 1.0, 0.0};
    double r2[3] = {0.0, 1.0, 0.0};
    double v2[3] = {0.0, 0.0, 1.0};
    double r3[3] = {0.0, 0.0, 1.0};
    double v3[3] = {1.0, 0.0, 0.0};

    // Simulazione
    for (int i = 0; i < years * 365 / dt; i++) {
        step(r1, v1, r2, v2, r3, v3, m1, m2, m3, dt);
    }

    // Stampa delle posizioni finali dei corpi
    printf("Posizione finale del corpo 1: (%lf, %lf, %lf)\n", r1[0], r1[1], r1[2]);
    printf("Posizione finale del corpo 2: (%lf, %lf, %lf)\n", r2[0], r2[1], r2[2]);
    printf("Posizione finale del corpo 3: (%lf, %lf, %lf)\n", r3[0], r3[1], r3[2]);

    return 0;
}
