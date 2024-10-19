#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <time.h>

#include "init.cpp"
#include "input.cpp"

void simulArc(int max, int min);
bool conditionOfColor(int max, int min);
void changingFruitPos();
void growingSnake();
void displaySnake();
void updateSnake();
SDL_Texture* loadTexture(char* path);



void prepareScene(void){
    //simulArc(207, 29);

    SDL_SetRenderDrawColor(app.renderer, bgColor.red, bgColor.green, bgColor.blue, 255);
    SDL_RenderClear(app.renderer);
}


void presentScene(void){
    
    SDL_RenderPresent(app.renderer);
}

void drawPlayer(void){

    if(!losingGame){
        updateSnake();
    }
    
    for(int i = 1; i < player.size(); i++){
        if(checkCollision(player[0].rect, player[i].rect)){
            losingGame = true;
        }
    }
    
    if(checkCollision(player[0].rect, fruit)){
        ateFruit = true;

        changingFruitPos();
    }

    traversingScreen();
    displaySnake();
}

void drawFruit(SDL_Texture* texture){

    SDL_QueryTexture(texture, NULL, NULL, &fruit.w, &fruit.h);
    SDL_RenderCopy(app.renderer, texture, NULL, &fruit);
}

void changingFruitPos(){
    srand(time(NULL));

    fruit.x = (rand() % SCREEN_WIDTH) - FRUIT_WIDTH;
    fruit.y = (rand() % SCREEN_HEIGHT) - FRUIT_HEIGHT;
}

void growSnake(){

}

void displaySnake(){
    
    SDL_QueryTexture(currentHeadTexture, NULL, NULL, &player[0].rect.w, &player[0].rect.h);
    SDL_RenderCopy(app.renderer, currentHeadTexture, NULL, &player[0].rect);

    SDL_SetRenderDrawColor(app.renderer, PLAYER_COLOR_RED, PLAYER_COLOR_GREEN, PLAYER_COLOR_BLUE, 255);

    for(int i = 1; i < player.size(); i++){
        SDL_RenderDrawRect(app.renderer, &player[i].rect);
        SDL_RenderFillRect(app.renderer, &player[i].rect);
    }
}

void updateSnake(){
    Snake newHead = Snake(player[0].rect.x + direction.x, player[0].rect.y + direction.y, PLAYER_WIDTH, PLAYER_HEIGHT);
    changingHead();
    player.insert(player.begin(), newHead);

    if(!ateFruit){
        player.pop_back();
    }
    else{
        ateFruit = false;
    }
    
}




/*void simulArc(int max, int min){

    switch(changy % 6){
        case 0: bgColor.green = (bgColor.green + 1); if(bgColor.blue == min && bgColor.green == max && bgColor.red == max){changy++;} break;
        case 1: bgColor.red = (bgColor.red - 1); if(bgColor.blue == min && bgColor.green == max && bgColor.red == min){changy++;} break;
        case 2: bgColor.blue = (bgColor.blue + 1); if(bgColor.blue == max && bgColor.green == max && bgColor.red == min){changy++;} break;
        case 3: bgColor.green = (bgColor.green - 1); if(bgColor.blue == max && bgColor.green == min && bgColor.red == min){changy++;} break;
        case 4: bgColor.red = (bgColor.red + 1); if(bgColor.blue == max && bgColor.green == min && bgColor.red == max){changy++;} break;
        case 5: bgColor.blue = (bgColor.blue - 1); if(bgColor.blue == min && bgColor.green == min && bgColor.red == max){changy++;} break;
    }  
}*/