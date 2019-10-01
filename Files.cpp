#include "Files.hpp"
#ifndef __ANDROID__
#include "SDL2/SDL.h"
std::string FilePrefix = "assets/";
#endif
#ifdef __ANDROID__
#include "SDL.h"
std::string FilePrefix = "";
#endif

std::string getFileAsString(std::string FileName){

    std::string FileAndPath = FilePrefix+FileName;

    SDL_RWops * pFile = SDL_RWFromFile( FileAndPath.c_str() , "r" );
        char buffer[260] = {NULL};
        SDL_RWread(pFile, &buffer,sizeof(buffer),1);
        SDL_RWclose(pFile);
        std::string sbuffer = buffer;

        return sbuffer; 


}
