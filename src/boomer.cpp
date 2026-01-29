#include <iostream>
#include <SDL3/SDL.h>
#include "screenshot.h"

// expr is some expression that signifies an error when false
#define SDL_ASSERT(expr) \
if(!(expr)) { \
    std::cout << "SDL Error at: " << __FILE__ << ":" << __LINE__ << ": "; \
    std::cout << "SDL_GetError(): " << SDL_GetError() << std::endl; \
    std::exit(1); \
}

using namespace std;

int main(int argc, char** argv) {
    SDL_ASSERT(SDL_Init(SDL_INIT_VIDEO) != false);

    SDL_Window* window = SDL_CreateWindow("Boomer", 0, 0, SDL_WINDOW_HIGH_PIXEL_DENSITY | SDL_WINDOW_FULLSCREEN | SDL_WINDOW_NOT_FOCUSABLE);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);
    SDL_ASSERT(window != NULL);
    SDL_ASSERT(renderer != NULL);
    
    SDL_FPoint mouse_fpos = {};
    SDL_GetGlobalMouseState(&mouse_fpos.x, &mouse_fpos.y);
    SDL_Point mouse_pos = {(int)mouse_fpos.x, (int)mouse_fpos.y};
    SDL_DisplayID display_id = SDL_GetDisplayForPoint(&mouse_pos);
    SDL_ASSERT(display_id != 0);
    const SDL_DisplayMode* display_mode = SDL_GetDesktopDisplayMode(display_id);
    SDL_ASSERT(display_mode != NULL);
    SDL_ASSERT(SDL_SetWindowFullscreenMode(window, display_mode) != false);
    SDL_ASSERT(SDL_SyncWindow(window));
    
    // TODO: screenshot
    
    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) running = false;
        }
        
        SDL_ASSERT(SDL_SetRenderDrawColorFloat(renderer, 0.0, 0.0, 0.0, 0.0) != false);
        SDL_ASSERT(SDL_RenderClear(renderer) != false);
        // TODO: display screenshot
        SDL_ASSERT(SDL_RenderPresent(renderer) != false);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
