#pragma once
#ifdef __ANDROID__
#include"SDL_image.h"
#endif

#ifndef __ANDROID__
#include"SDL2/SDL_image.h"
#endif
#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <fstream>


struct TileSet{
    TileSet() =default;
    ~TileSet() =default;

    
int TileWidth;
int TileHeight;
int NumOfColums;
int NumOfRows;
unsigned int TextureID;

};
 
struct Tile{
unsigned int TileSetid = 0;
float xPos =0;
float yPos =0;
float xScale =1.0;
float yScale= 1.0;
int currentCollum =0;
int currentRow =0;
double rotationAngle =0;
SDL_RendererFlip flip = SDL_FLIP_NONE;


};



const TileSet LoadTileSet(std::string FileName , SDL_Renderer* Renderer );

class Textures{

    public:
    static Textures*  Instance();
    Textures(){
    int imgFlags = IMG_INIT_PNG;
        if (IMG_Init(imgFlags) != imgFlags) {
            std::cout << IMG_GetError() << std::endl;
        }
    }
    ~Textures();
    bool Load(std::string FileName,  SDL_Renderer* pRender);
    void draw(unsigned int Textureid, int xPos, int yPos, int width, int height,
            float xScale, float yScale, SDL_Renderer *pRender, SDL_RendererFlip flip);
   
    void drawFrame(unsigned int Textureid, int xPos, int yPos, int width, int height,
                int currentRow, int currentCol,float xScale ,float yScale  ,double rotAngle,
                SDL_Renderer *pRender, SDL_RendererFlip flip);
    void drawTile(Tile instance , SDL_Renderer* render);
    unsigned int CheckedTextureLoad(std::string FileName,SDL_Renderer* pRender);
    // use this for all of image/texture loading.
    // checks image is not loaded, 
    // loads it into memory and converts it to a texture if it is not loaded,
    // and returns the id you can call it by.
    unsigned int GetTextureID(std::string FileName);
    // get Textureid number from the file name

    bool AddTileSet(std::string FileName , SDL_Renderer* render);
    unsigned int GetTileSetID(std::string FileName);    
    int getTCollums(unsigned int TilesetID);
    int getTRows(unsigned int TilesetID);
    int getWidth(unsigned int TilesetID);
    int getHeight(unsigned int TilesetID);

    private:

    std::map< unsigned int , SDL_Texture*> m_TextureMap;
    std::map< std::string , unsigned int> m_TextureidMap;
    std::map< std::string ,unsigned int  >m_TileSetidMap;
    std::map< unsigned int, TileSet >m_TileSetMap;
    static Textures* s_pInstance;
    unsigned int m_nextTextureID;
    unsigned int m_nextTileID;

};

using gfx2D = Textures;