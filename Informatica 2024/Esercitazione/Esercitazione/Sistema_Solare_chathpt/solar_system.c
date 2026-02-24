#include "solar_system.h"
#include <stdlib.h>
#include <math.h>
#include "/usr/local/Cellar/sdl2_gfx/1.0.4/include/SDL2/SDL2_gfxPrimitives.h"



#define G 6.67430e-11
#define NUM_BODIES 10
#define SCALE 1e-9

static Body bodies[NUM_BODIES];
static int body_count = 0;

void initialize_solar_system() {
    // Sole
    add_body(400, 300, 0, 0, 1.989e30, 255, 255, 0);  // Sole
    // Terra
    add_body(400 + 150, 300, 0, 29780, 5.972e24, 0, 0, 255);  // Terra
    // Luna
    add_body(400 + 150 + 38, 300, 0, 29780 + 1022, 7.348e22, 200, 200, 200);  // Luna
}

void add_body(double x, double y, double vx, double vy, double mass, int r, int g, int b) {
    if (body_count < NUM_BODIES) {
        bodies[body_count].x = x;
        bodies[body_count].y = y;
        bodies[body_count].vx = vx;
        bodies[body_count].vy = vy;
        bodies[body_count].mass = mass;
        bodies[body_count].r = r;
        bodies[body_count].g = g;
        bodies[body_count].b = b;
        body_count++;
    }
}

void update_solar_system() {
    for (int i = 0; i < body_count; ++i) {
        double fx = 0, fy = 0;
        for (int j = 0; j < body_count; ++j) {
            if (i != j) {
                double dx = bodies[j].x - bodies[i].x;
                double dy = bodies[j].y - bodies[i].y;
                double distance = sqrt(dx * dx + dy * dy);
                double force = G * bodies[i].mass * bodies[j].mass / (distance * distance);
                fx += force * dx / distance;
                fy += force * dy / distance;
            }
        }
        bodies[i].vx += fx / bodies[i].mass;
        bodies[i].vy += fy / bodies[i].mass;
    }

    for (int i = 0; i < body_count; ++i) {
        bodies[i].x += bodies[i].vx * SCALE;
        bodies[i].y += bodies[i].vy * SCALE;
    }
}

void render_solar_system(SDL_Renderer* renderer) {
    for (int i = 0; i < body_count; ++i) {
        filledCircleRGBA(renderer, (int)bodies[i].x, (int)bodies[i].y, 5, bodies[i].r, bodies[i].g, bodies[i].b, 255);
    }
}
