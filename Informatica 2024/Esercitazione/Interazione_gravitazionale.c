#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Costanti
#define G 6.67430e-11 // Costante gravitazionale in m^3 kg^-1 s^-1
#define M 1.989e30    // Massa del sole in kg
#define DT 86400      // Passo di tempo in secondi (1 giorno)

// Struttura per rappresentare un vettore 2D
typedef struct {
    double x;
    double y;
} Vector2D;

// Funzione per chiedere i parametri all'utente
void Ask_Parameters(double* m1, double* r, int* years) {
    printf("Inserire la massa del pianeta (in kg): ");
    scanf("%lf", m1);
    printf("Inserire la distanza tra il pianeta e la stella (in metri): ");
    scanf("%lf", r);
    printf("Inserire il numero di anni da simulare: ");
    scanf("%d", years);
}

// Funzione per calcolare la forza gravitazionale
Vector2D calculateGravitationalForce(Vector2D position, double mass) {
    Vector2D force;
    double distance = sqrt(position.x * position.x + position.y * position.y);
    double magnitude = (G * M * mass) / (distance * distance);

    force.x = -magnitude * position.x / distance;
    force.y = -magnitude * position.y / distance;

    return force;
}

// Funzione per aggiornare la posizione e la velocità del pianeta
void updatePositionAndVelocity(Vector2D *position, Vector2D *velocity, double mass) {
    Vector2D force = calculateGravitationalForce(*position, mass);

    velocity->x += force.x / mass * DT;
    velocity->y += force.y / mass * DT;

    position->x += velocity->x * DT;
    position->y += velocity->y * DT;
}

// Funzione per scrivere i dati dell'orbita su file
void Write_Data(Vector2D position, double mass, Vector2D velocity, int steps) {
    FILE *file = fopen("orbita.csv", "w");
    if (file == NULL) {
        printf("Errore nell'apertura del file!\n");
        exit(1);
    }

    fprintf(file, "Giorno,Posizione X (m),Posizione Y (m)\n");

    for (int i = 0; i < steps; i++) {
        fprintf(file, "%d,%.2f,%.2f\n", i, position.x, position.y);
        updatePositionAndVelocity(&position, &velocity, mass);
    }

    fclose(file);
    printf("Simulazione completata. Dati salvati in 'orbita.csv'.\n");
}

int main() {
    double m1, r;
    int years;
    
    // Richiesta parametri all'utente
    Ask_Parameters(&m1, &r, &years);

    // Impostazione dei parametri iniziali del pianeta
    Vector2D position = {r, 0}; // Posizione iniziale a distanza r dalla stella
    Vector2D velocity = {0, sqrt(G * M / r)}; // Velocità orbitale iniziale

    // Numero di passi totali
    int steps = years * 365;

    // Scrittura dei dati
    Write_Data(position, m1, velocity, steps);

    return 0;
}
