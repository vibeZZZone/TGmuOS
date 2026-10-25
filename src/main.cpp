#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <cstdio>

int main(int argc, char** argv) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::fprintf(stderr, "SDL_Init: %s\n", SDL_GetError());
        return 1;
    }
    SDL_Window* w = SDL_CreateWindow("teleSP", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
    if (!w) { std::fprintf(stderr, "window: %s\n", SDL_GetError()); SDL_Quit(); return 1; }
    SDL_Renderer* r = SDL_CreateRenderer(w, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!r) { std::fprintf(stderr, "renderer: %s\n", SDL_GetError()); SDL_DestroyWindow(w); SDL_Quit(); return 1; }
    if (TTF_Init() != 0) { std::fprintf(stderr, "TTF_Init: %s\n", TTF_GetError()); }
    bool run = true;
    while (run) {
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) run = false;
            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) run = false;
        }
        SDL_SetRenderDrawColor(r, 20, 20, 30, 255);
        SDL_RenderClear(r);
        SDL_RenderPresent(r);
    }
    TTF_Quit();
    SDL_DestroyRenderer(r);
    SDL_DestroyWindow(w);
    SDL_Quit();
    return 0;
}
