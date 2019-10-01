#pragma once
#ifndef __ANDROID__
#include "SDL2/SDL.h"
#endif
#ifdef __ANDROID__
#include "SDL.h"
#endif
#include "Settings.hpp"
#include "Timer.hpp"
#include "Stage.hpp"

class Game{

    public:
    Game(); 
     
    ~Game();

    void GameLoop();
    void update();

    void testInit();
    void testUpdate();

    private:
    Settings m_settings;    
    SDL_Window* m_Window;
    SDL_Renderer*  m_Render;
    bool IsOpened;
    SDL_Event evnt;
    Stage TestStage;
    TimerF TimerTest;
    TimerF FrameTimer;
};