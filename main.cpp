
#include<iostream>
#include "SDL2/SDL.h"
#include"Game.hpp"

int main(int argc , char *argv[]){

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_TIMER );

    Game DaGame;
    DaGame.GameLoop();
  //  DaGame.~Game();
    
   

    return 0;
}