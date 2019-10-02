#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#ifndef __ANDROID__
#include "SDL2/SDL.h"
#endif
#ifdef __ANDROID__
#include "SDL.h"
#endif
#include "Files.hpp"

class Settings{
    public:
    Settings();
    ~Settings();
    bool Load();
    bool Save();


    

    int m_width;
    int m_height;
    bool m_FullScreen;
    int m_scale;

};