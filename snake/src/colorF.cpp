#pragma once

#include <cstdint>
#include "structs.h"

class Color{
    
    public:
        uint8_t red;
        uint8_t green;
        uint8_t blue;
        uint8_t alpha;

        Color(int r, int g, int b, int a){
            this->red = r;
            this->green = g;
            this->blue = b;
            this->alpha = a;
        }

};

class Snake{
    public:
        SDL_Rect rect;
        

        Snake(int x, int y, int w, int h){
            this->rect.x = x;
            this->rect.y = y;
            this->rect.w = w;
            this->rect.h = h;
        }

        Snake(){}
};