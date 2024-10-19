#include <SDL2/SDL.h>

#include "init.cpp"
#include "input.cpp"
#include "draw.cpp"

 
int main(int argc, char *argv[])
{
    //To Compile use
    //g++ src/main.cpp -o build/main.exe -I include -L lib -lSDL2main -lSDL2

    memset(&app, 0, sizeof(App));
    //memset(&player1, 0, sizeof(Entity));
    
    initSDL();
    initPlayerHead();
    initFruit();

    

    atexit(SDL_Quit);

    while(1){
        prepareScene();

        drawPlayer();
        drawFruit(fruitTexture);

        doInput();
        presentScene();

        //FrameRate
        SDL_Delay(64);
    }

    return 0;
}
