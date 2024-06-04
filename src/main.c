#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <math.h>
#include <stdio.h>

void draw_test(SDL_Renderer *renderer, int center_x, int center_y);

int main() {
    double time;
    
    SDL_Window *window;
    SDL_Renderer *renderer;

    SDL_Init(SDL_INIT_VIDEO);

    SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer);

    SDL_SetWindowTitle(window, "Simple SDL2 Window");

    int running = 1;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }

        SDL_SetRenderDrawColor(renderer, 128, 128, 128, 255);
        SDL_RenderClear(renderer);
        time = SDL_GetTicks();
        draw_test(renderer, 320 + 10 * cos(time / 60), 240 + 20 * sin(time / 60));
        printf("time: %f\n", time);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

void draw_test(SDL_Renderer *renderer, int center_x, int center_y) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    for (int i = 0; i < 360; i++) {
        SDL_RenderDrawPoint(renderer, center_x + sin(i) * 50, center_y + cos(i) * 50);
    }    
}
