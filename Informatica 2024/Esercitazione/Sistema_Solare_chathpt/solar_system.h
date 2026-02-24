#ifndef SOLAR_SYSTEM_H
#define SOLAR_SYSTEM_H

#include <SDL2/SDL.h>

typedef struct {
    double x, y;
    double vx, vy;
    double mass;
    int r, g, b;
} Body;

void initialize_solar_system();
void update_solar_system();
void render_solar_system(SDL_Renderer* renderer);
void add_body(double x, double y, double vx, double vy, double mass, int r, int g, int b);

#endif
