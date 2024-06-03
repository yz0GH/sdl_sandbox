#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>

struct Pos {
    int x;
    int y;
};

void H_DrawCircleMP(SDL_Renderer *renderer, int x, int y, int r);

int main() {
    
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
        H_DrawCircleMP(renderer, 320, 240, 50);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

void H_DrawCircleMP(SDL_Renderer *renderer, int x, int y, int r) {
    struct Pos pos = {x, y - r};
    SDL_SetRenderDrawColor(renderer, 255, 150, 150, 255);
    SDL_RenderDrawPoint(renderer, x, y);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawPoint(renderer, pos.x, pos.y);    
    for (int i = 0; i < 15; i++) {
        SDL_RenderDrawPoint(renderer, x , y + i);
    }
}
