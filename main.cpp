
#include<iostream>
#ifndef __ANDROID__
#include "SDL2/SDL.h"
#endif
#ifdef __ANDROID__
#include "SDL.h"
#endif
#include"Game.hpp"

int main(int argc , char *argv[]){

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_TIMER );

    Game DaGame;
    DaGame.GameLoop();
  //  DaGame.~Game();
    
   

    return 0;
}