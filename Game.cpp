#include "Game.hpp"
#include "Files.hpp"

// Constructor  and initilizer list for the game object. Initializes the window and renderer
Game::Game(): 
    m_settings(Settings()),
    m_Window(SDL_CreateWindow("Game Scrap", SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED, m_settings.m_width , m_settings.m_height, SDL_WINDOW_SHOWN  )),
    m_Render(SDL_CreateRenderer(m_Window, -1 , SDL_RENDERER_ACCELERATED)),
    IsOpened(true),
    m_Input(&evnt)
{
    testInit();

}

// Destructor: 
Game::~Game()
{
    SDL_DestroyRenderer(m_Render);
    SDL_DestroyWindow(m_Window);
}

void Game::GameLoop(){
    while(IsOpened){
        while(SDL_PollEvent(&evnt)){
        if(evnt.type == SDL_QUIT){ IsOpened = false;}
        }
        m_Input.inputUpdate();
        update();
    }
}

void Game::update(){

  
    SDL_RenderClear(m_Render);

    testUpdate();

    SDL_RenderPresent(m_Render);


}


void Game::testInit(){
TestStage.init(m_Render , m_Input.getInputKB());
}

void Game::testUpdate(){

TestStage.update(m_Render);

 }

