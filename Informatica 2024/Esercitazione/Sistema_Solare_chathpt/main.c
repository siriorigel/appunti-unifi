#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include "solar_system.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define FRAME_RATE 60

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Simulazione Sistema Solare", 
                                          SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
                                          WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    initialize_solar_system();

    int running = 1;
    Uint32 frame_delay = 1000 / FRAME_RATE;
    while (running) {
        Uint32 frame_start = SDL_GetTicks();
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }
        
        // Update physics
        update_solar_system();

        // Render
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        render_solar_system(renderer);

        SDL_RenderPresent(renderer);

        // Frame rate control
        Uint32 frame_time = SDL_GetTicks() - frame_start;
        if (frame_delay > frame_time) {
            SDL_Delay(frame_delay - frame_time);
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
