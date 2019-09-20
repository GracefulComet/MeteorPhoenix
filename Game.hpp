#pragma once
#include "SDL2/SDL.h"
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