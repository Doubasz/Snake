#ifndef struct_h
#define struct_h

#include <SDL2/SDL.h>


struct App{
    SDL_Renderer* renderer;
    SDL_Window* window;
};

struct Position{
    int x;
    int y;
};

#endif