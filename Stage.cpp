#include"Stage.hpp"

void Stage::init(SDL_Renderer* render , vGamePadKB* pad){
#ifdef __ANDROID__
gfx2D::Instance()->AddTileSet("basic.tiles", render);
unsigned int Ref = gfx2D::Instance()->GetTileSetID("basic.tiles");
#endif
#ifndef __ANDROID__
gfx2D::Instance()->AddTileSet("assets/basic.tiles", render);
unsigned int Ref = gfx2D::Instance()->GetTileSetID("assets/basic.tiles");
#endif

for(int x = 0; x < 60; x++ ){
    for (int y =0; y < 30; y++){
        Bg1[x][y].TileSetid = Ref;
        Bg1[x][y].xScale = 2.0;
        Bg1[x][y].yScale = 2.0;
        Bg1[x][y].xPos = x * gfx2D::Instance()->getWidth(Ref) * Bg1[x][y].xScale;
        Bg1[x][y].yPos = y * gfx2D::Instance()->getHeight(Ref) * Bg1[x][y].yScale;
        if(y == 0){
            Bg1[x][y].currentCollum =0;
            Bg1[x][y].currentRow = 0;

        }else{
            Bg1[x][y].currentCollum =6;
            Bg1[x][y].currentRow = 1;
            }
        }

    }
 gpad = pad;
 selectedx = selectedy = 0;
}

void Stage::update(SDL_Renderer* render){

if (gpad->dpadRight.buttonDown && !gpad->dpadRight.buttonHeld){
    selectedx++;
    if(selectedx >60){
        selectedx = 0;
    }
}
if (gpad->dpadLeft.buttonDown && !gpad->dpadLeft.buttonHeld){
    if(selectedx == 0){
        selectedx = 60;
    }selectedx--;

}
if (gpad->dpadDown.buttonDown && !gpad->dpadDown.buttonHeld ){
    selectedy++;
    if(selectedy >30){
        selectedy = 0;
    }
}
if (gpad->dpadUp.buttonDown && !gpad->dpadUp.buttonHeld ){
    if(selectedy == 0){
        selectedy = 30;
    }selectedy--;

}
if(gpad->Action.buttonDown && !gpad->Action.buttonHeld){
    Bg1[selectedx][selectedy].currentCollum++;
    if(Bg1[selectedx][selectedy].currentCollum >8 ){
        Bg1[selectedx][selectedy].currentRow++;
        Bg1[selectedx][selectedy].currentCollum = 0;
    }

}
    if(Bg1[selectedx][selectedy].currentRow >15 ){
        Bg1[selectedx][selectedy].currentRow = 0;
    }
    for(int i =0; i < 60; i++){
        for(int j =0; j < 30; j++){
            gfx2D::Instance()->drawTile( Bg1[i][j], render );
        }
    }

}