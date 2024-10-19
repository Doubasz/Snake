#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <vector>

#include "structs.h"
#include "def.h"
#include "colorF.cpp"

App app;
Color bgColor = Color(BG_COLOR_RED, BG_COLOR_GREEN, BG_COLOR_BLUE, 255);

std::vector<Snake> player;
bool ateFruit = false;
SDL_Texture* headTexture[4];
SDL_Texture* currentHeadTexture;

SDL_Rect fruit;
char* pathFruit = "assets/apple.png";
SDL_Texture* fruitTexture;

Position direction;

bool losingGame = false;

//int changy = 0;

void initSDL(void){
    
    int rendererFlags, windowFlags;

    rendererFlags = SDL_RENDERER_ACCELERATED; 

    windowFlags = 0;

    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

    // Checks if sdl is initialized

    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("Couldn't intitialize SDL: %s\n", SDL_GetError());
        exit(1);
    }

    app.window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);

    if(!app.window){
        printf("Failed to open %d x %d window: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
        exit(1);
    }


    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

    app.renderer = SDL_CreateRenderer(app.window, -1, rendererFlags);

    if(!app.renderer){
        printf("Failed to create renderer: %s\n", SDL_GetError());
        exit(1);
    }

}

SDL_Texture* loadTexture(char* path){
    SDL_Texture* texture;

    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", path);

    texture = IMG_LoadTexture(app.renderer, path);

    return texture;
}

void initPlayerHead(void){
    player.clear();
    losingGame = false;

    Snake temp = Snake(STARTING_POSX, STARTING_POSY, PLAYER_WIDTH, PLAYER_HEIGHT);
    direction.x = SPEED;
    direction.y = 0;

    headTexture[0] = loadTexture(HEAD_RIGHT);
    headTexture[1] = loadTexture(HEAD_LEFT);
    headTexture[2] = loadTexture(HEAD_DOWN);
    headTexture[3] = loadTexture(HEAD_UP);

    player.push_back(temp);

    Snake temp1 = Snake(STARTING_POSX - PLAYER_WIDTH, STARTING_POSY, PLAYER_WIDTH, PLAYER_HEIGHT);

    player.push_back(temp1);

}

void initFruit(void){
    fruitTexture = loadTexture(pathFruit);

    fruit.x = STARTING_POSX_FRUIT;
    fruit.y = STARTING_POSY_FRUIT;
    fruit.w = FRUIT_WIDTH;
    fruit.h = FRUIT_HEIGHT;
}

void restartGame(){
    initPlayerHead();
    initFruit();
}