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
    if(pFile != NULL){
        int filesize = pFile->size(pFile);
        char* cbuffer = new char[filesize];
        SDL_RWread(pFile, cbuffer,sizeof(char) * filesize ,1);
        SDL_RWclose(pFile);
        std::string sbuffer = cbuffer;
        delete[](cbuffer);
        return sbuffer; 
    }else{
        std::string sBuffer;
        sBuffer.clear();
        return sBuffer;
    }




}
