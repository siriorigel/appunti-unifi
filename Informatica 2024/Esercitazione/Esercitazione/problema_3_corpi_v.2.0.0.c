#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Costanti
#define G 6.67430e-11 // Costante gravitazionale in m^3 kg^-1 s^-1
#define DT 86400      // Passo di tempo in secondi (1 giorno)

// Struttura per rappresentare un vettore 2D
typedef struct {
    double x;
    double y;
} Vector2D;

// Struttura per rappresentare un corpo celeste
typedef struct {
    Vector2D position;
    Vector2D velocity;
    double mass;
    double radius;
} Body;

// Funzione per calcolare la forza gravitazionale tra due corpi
Vector2D calculateGravitationalForce(Body a, Body b) {
    Vector2D force = {0, 0};
    double dx = b.position.x - a.position.x;
    double dy = b.position.y - a.position.y;
    double distance = sqrt(dx * dx + dy * dy);
    
    if (distance > a.radius + b.radius) {
        double magnitude = (G * a.mass * b.mass) / (distance * distance);
        force.x = magnitude * dx / distance;
        force.y = magnitude * dy / distance;
    }

    return force;
}

// Funzione per aggiornare la posizione e la velocità di un corpo
void updatePositionAndVelocity(Body *body, Vector2D totalForce) {
    body->velocity.x += totalForce.x / body->mass * DT;
    body->velocity.y += totalForce.y / body->mass * DT;

    body->position.x += body->velocity.x * DT;
    body->position.y += body->velocity.y * DT;
}

// Funzione per chiedere i parametri all'utente
void Ask_Parameters(double* m1, double* r1, double* m2, double* r2, double* rad1, double* rad2, int* years) {
    printf("Inserire la massa del primo pianeta (in kg): ");
    scanf("%lf", m1);
    printf("Inserire la distanza del primo pianeta dal sole (in metri): ");
    scanf("%lf", r1);
    printf("Inserire il raggio del primo pianeta (in metri): ");
    scanf("%lf", rad1);
    printf("Inserire la massa del secondo pianeta (in kg): ");
    scanf("%lf", m2);
    printf("Inserire la distanza del secondo pianeta dal primo pianeta (in metri): ");
    scanf("%lf", r2);
    printf("Inserire il raggio del secondo pianeta (in metri): ");
    scanf("%lf", rad2);
    printf("Inserire il numero di anni da simulare: ");
    scanf("%d", years);
}

// Funzione per scrivere i dati dell'orbita su file
void Write_Data(Body bodies[], int steps) {
    FILE *file = fopen("orbita.csv", "w");
    if (file == NULL) {
        printf("Errore nell'apertura del file!\n");
        exit(1);
    }

    fprintf(file, "Giorno,Posizione X Sole,Posizione Y Sole,Posizione X Terra,Posizione Y Terra,Posizione X Luna,Posizione Y Luna\n");

    for (int i = 0; i < steps; i++) {
        fprintf(file, "%d,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f\n", i, 
                bodies[0].position.x, bodies[0].position.y,
                bodies[1].position.x, bodies[1].position.y,
                bodies[2].position.x, bodies[2].position.y);

        Vector2D force01 = calculateGravitationalForce(bodies[0], bodies[1]);
        Vector2D force02 = calculateGravitationalForce(bodies[0], bodies[2]);
        Vector2D force12 = calculateGravitationalForce(bodies[1], bodies[2]);

        Vector2D totalForce0 = {force01.x + force02.x, force01.y + force02.y};
        Vector2D totalForce1 = {-force01.x + force12.x, -force01.y + force12.y};
        Vector2D totalForce2 = {-force02.x - force12.x, -force02.y - force12.y};

        updatePositionAndVelocity(&bodies[0], totalForce0);
        updatePositionAndVelocity(&bodies[1], totalForce1);
        updatePositionAndVelocity(&bodies[2], totalForce2);

        // Verifica delle collisioni
        if (sqrt(pow(bodies[0].position.x - bodies[1].position.x, 2) + pow(bodies[0].position.y - bodies[1].position.y, 2)) <= (bodies[0].radius + bodies[1].radius)) {
            printf("Collisione tra Sole e Terra al giorno %d\n", i);
            break;
        }

        if (sqrt(pow(bodies[0].position.x - bodies[2].position.x, 2) + pow(bodies[0].position.y - bodies[2].position.y, 2)) <= (bodies[0].radius + bodies[2].radius)) {
            printf("Collisione tra Sole e Luna al giorno %d\n", i);
            break;
        }

        if (sqrt(pow(bodies[1].position.x - bodies[2].position.x, 2) + pow(bodies[1].position.y - bodies[2].position.y, 2)) <= (bodies[1].radius + bodies[2].radius)) {
            printf("Collisione tra Terra e Luna al giorno %d\n", i);
            break;
        }
    }

    fclose(file);
    printf("Simulazione completata. Dati salvati in 'orbita.csv'.\n");
}

int main() {
    double m1, r1, m2, r2, rad1, rad2;
    int years;
    
    // Richiesta parametri all'utente
    Ask_Parameters(&m1, &r1, &m2, &r2, &rad1, &rad2, &years);

    // Definizione dei corpi celesti
    Body sun = {{0, 0}, {0, 0}, 1.989e30, 6.9634e8}; // Raggio del Sole in metri
    Body earth = {{r1, 0}, {0, sqrt(G * sun.mass / r1)}, m1, rad1};
    Body moon = {{r1 + r2, 0}, {0, sqrt(G * m1 / r2) + earth.velocity.y}, m2, rad2};

    Body bodies[3] = {sun, earth, moon};

    // Numero di passi totali
    int steps = years * 365;

    // Scrittura dei dati
    Write_Data(bodies, steps);

    return 0;
}
