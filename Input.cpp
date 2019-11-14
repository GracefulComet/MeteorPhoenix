#include "Input.hpp"
#include "iostream"

GameButtonKB ButtonPressed(GameButtonKB button){
    if(button.buttonDown == true){
        button.buttonHeld = true;
    }
    button.buttonDown = true;
    button.buttonUp = false;
    button.buttonRelease = false;
    return button;
}

GameButtonKB ButtonReleased(GameButtonKB button){
    if(button.buttonUp == false){
        button.buttonRelease = true;
    }else{button.buttonRelease = false;}
    button.buttonDown = false;
    button.buttonHeld = false;
    button.buttonUp = true;

return button;
}


Input::Input(SDL_Event* inputEvnt){
    pEvnt = inputEvnt;


    PadKB.dpadDown.keyC = SDLK_DOWN;
    PadKB.dpadDown.buttonDown = false;
    PadKB.dpadDown.buttonUp = false;
    PadKB.dpadUp.keyC = SDLK_UP;
    PadKB.dpadUp.buttonDown = false;
    PadKB.dpadUp.buttonUp = false;
    PadKB.dpadLeft.keyC = SDLK_LEFT;
    PadKB.dpadLeft.buttonDown = false;
    PadKB.dpadLeft.buttonUp = false;
    PadKB.dpadRight.keyC = SDLK_RIGHT;
    PadKB.dpadRight.buttonDown = false;
    PadKB.dpadRight.buttonUp = false;
    PadKB.Action.keyS = SDL_SCANCODE_A;
    PadKB.Action.keyC = SDLK_RETURN;
    PadKB.Action.buttonDown = false;
    PadKB.Action.buttonUp = false;
    PadKB.Negate.keyC = SDLK_RSHIFT;
    PadKB.Negate.buttonDown = false;
    PadKB.Negate.buttonUp = false;
    PadKB.Start.keyC = SDLK_LSHIFT;
    PadKB.Start.buttonDown = false;
    PadKB.Start.buttonUp = false;





}
Input::~Input(){
    pEvnt = nullptr;
}

void Input::KBSCkeyCheck( const Uint8 *State, GameButtonKB button ){}
void Input::KBKCkeyCheck( const Uint8 *State, GameButtonKB button ){}

void Input::KBupdateKC(){

}

void Input::KBupdateSC(){
     SDL_PumpEvents();
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    if(state[PadKB.Action.keyS] == 1){
        PadKB.Action = ButtonPressed( PadKB.Action);
    }
    if(state[PadKB.Action.keyS] < 1){
        PadKB.Action = ButtonReleased(PadKB.Action);
    }


}

void Input::inputUpdate(){




    KBupdateSC();


    
   if( pEvnt->type == SDL_KEYDOWN ){

  //  std::cout << "keydown debug" <<std::endl;   
       if(pEvnt->key.keysym.scancode == SDL_SCANCODE_DOWN){
           if(PadKB.dpadDown.buttonDown){
               PadKB.dpadDown.buttonHeld = true;
           }
           PadKB.dpadDown.buttonDown = true;
           PadKB.dpadDown.buttonUp = false;
       }
        if(pEvnt->key.keysym.sym == PadKB.dpadUp.keyS){
            if(PadKB.dpadUp.buttonDown){
               PadKB.dpadUp.buttonHeld = true;
           }
           PadKB.dpadUp.buttonDown = true;
           PadKB.dpadUp.buttonUp = false;
       }
       if(pEvnt->key.keysym.sym == PadKB.dpadLeft.keyS){
           if(PadKB.dpadLeft.buttonDown){
               PadKB.dpadLeft.buttonHeld = true;
           }
           PadKB.dpadLeft.buttonDown = true;
           PadKB.dpadLeft.buttonUp = false;
       }
        if(pEvnt->key.keysym.sym == PadKB.dpadRight.keyS){
         if(PadKB.dpadRight.buttonDown){
               PadKB.dpadRight.buttonHeld = true;
           }
           PadKB.dpadRight.buttonDown = true;
           PadKB.dpadRight.buttonUp = false;
       }
        if(pEvnt->key.keysym.scancode == SDL_SCANCODE_A){
         if(PadKB.Action.buttonDown){
               PadKB.Action.buttonHeld = true;
           }
           PadKB.Action.buttonDown = true;
           PadKB.Action.buttonUp = false;
       }
        if(pEvnt->key.keysym.sym == PadKB.Negate.keyS){
         if(PadKB.Negate.buttonDown){
               PadKB.Negate.buttonHeld = true;
           }
           PadKB.Negate.buttonDown = true;
           PadKB.Negate.buttonUp = false;
       }       
        if(pEvnt->key.keysym.sym == PadKB.Start.keyS){
             if(PadKB.Start.buttonDown){
               PadKB.Start.buttonHeld = true;
           }
           PadKB.Start.buttonDown = true;
           PadKB.Start.buttonUp = false;
       } 
   }
   if( pEvnt->type == SDL_KEYUP ){
       if(pEvnt->key.keysym.sym == PadKB.dpadDown.keyS){
           PadKB.dpadDown.buttonDown = false;
           PadKB.dpadDown.buttonHeld = false;
           PadKB.dpadDown.buttonUp = true;

       }
        if(pEvnt->key.keysym.sym == PadKB.dpadUp.keyS){
           PadKB.dpadUp.buttonDown = false;
           PadKB.dpadUp.buttonHeld = false;
           PadKB.dpadUp.buttonUp = true;
       }
       if(pEvnt->key.keysym.sym == PadKB.dpadLeft.keyS){
           PadKB.dpadLeft.buttonDown = false; 
           PadKB.dpadLeft.buttonHeld = false;
           PadKB.dpadLeft.buttonUp = true;
       }
        if(pEvnt->key.keysym.sym == PadKB.dpadRight.keyS){
           PadKB.dpadRight.buttonDown = false;
           PadKB.dpadRight.buttonUp = true;
       }
        if(pEvnt->key.keysym.sym == PadKB.Action.keyS){
           PadKB.Action.buttonDown = false;
           PadKB.Action.buttonHeld = false;
           PadKB.Action.buttonUp = true;
       }
        if(pEvnt->key.keysym.sym == PadKB.Negate.keyS){
           PadKB.Negate.buttonHeld = false;
           PadKB.Negate.buttonDown = false;
           PadKB.Negate.buttonUp = true;
       }       
        if(pEvnt->key.keysym.sym == PadKB.Start.keyS){

           PadKB.Start.buttonHeld = false;
           PadKB.Start.buttonDown = false;
           PadKB.Start.buttonUp = true;
       } 
   }

}

vGamePadKB* Input::getInputKB(){
    return &PadKB;
}