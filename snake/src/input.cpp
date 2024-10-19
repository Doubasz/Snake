#pragma once

#include <SDL2/SDL.h>

#include "init.cpp"


void doInput(void){
    SDL_Event event;

    while(SDL_PollEvent(&event)){

        switch(event.type){

            case SDL_QUIT:
                exit(0);
                break;

            case SDL_KEYDOWN:

                switch(event.key.keysym.sym){

                    case SDLK_RIGHT:
                        if(direction.x != -SPEED){

                            direction.x = SPEED;
                            direction.y = 0;
                            break;
                        }

                    case SDLK_LEFT:
                        if(direction.x != SPEED){
                        
                            direction.x = -SPEED;
                            direction.y = 0; 
                            break;
                        }
                           
                    case SDLK_UP:
                        if(direction.y != SPEED){
                            
                            direction.x = 0;
                            direction.y = -SPEED;    
                            break;
                        }
                        
                    case SDLK_DOWN:
                        if(direction.y != -SPEED){
                            
                            direction.x = 0;
                            direction.y = SPEED;
                            break;
                        }

                    case SDLK_SPACE:
                        if(losingGame){
                            restartGame();
                        }
                }
                
            default:
                break;
        }
    }

    
}

void traversingScreen(void){
    for(int i = 0; i < player.size(); i++){
        if((player[i].rect.x + direction.x) > SCREEN_WIDTH){
            player[i].rect.x = -PLAYER_WIDTH;
        }

        if((player[i].rect.x + direction.x) < -PLAYER_WIDTH){
            player[i].rect.x = SCREEN_WIDTH;
        }

        if((player[i].rect.y + direction.y) > SCREEN_HEIGHT){
            player[i].rect.y = -PLAYER_HEIGHT;
        }

        if((player[i].rect.y + direction.y) < -PLAYER_HEIGHT){
            player[i].rect.y = SCREEN_HEIGHT;
        }
    }
    
}

bool checkCollision(SDL_Rect a, SDL_Rect b){
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    //Calculate the sides of rect B
    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;

    // If any of the sides from A are outside of B
    if(bottomA <= topB) return false;

    if(topA >= bottomB) return false;

    if(rightA <= leftB) return false;

    if(leftA >= rightB) return false;

    //If none of the sides from A are outside B
    return true;
}

void changingHead(){
    if(direction.x == SPEED){
        currentHeadTexture = headTexture[0];
    }
    else if(direction.x == -SPEED){
        currentHeadTexture = headTexture[1];
    }
    else if(direction.y == SPEED){
        currentHeadTexture = headTexture[2];
    }
    else if(direction.y == -SPEED){
        currentHeadTexture = headTexture[3];
    }
}