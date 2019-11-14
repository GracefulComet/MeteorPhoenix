#pragma once
#ifndef __ANDROID__
#include "SDL2/SDL.h"
#endif
#ifdef __ANDROID__
#include "SDL.h"
#endif
struct GameButtonKB{

    bool buttonDown;
    bool buttonRelease;
    bool buttonUp;
    bool buttonHeld;
    SDL_Keycode keyC;
    SDL_Scancode keyS;
};

GameButtonKB ButtonPressed(GameButtonKB button);
GameButtonKB ButtonReleased(GameButtonKB button);

struct vGamePadKB{

GameButtonKB dpadDown;
GameButtonKB dpadUp;
GameButtonKB dpadLeft;
GameButtonKB dpadRight;
GameButtonKB Action;
GameButtonKB Negate;
GameButtonKB Start;
};
// gathers input from SDL_events
class Input{
    public:
    Input(SDL_Event* inputEvent );
    void inputUpdate();
    void KBupdateSC();
    void KBKCkeyCheck(const Uint8* State, GameButtonKB button);
    void KBSCkeyCheck(const Uint8* State, GameButtonKB button);
    void KBupdateKC();
    vGamePadKB* getInputKB();
    ~Input();

    private:
    SDL_Event * pEvnt;
    vGamePadKB PadKB;

};

