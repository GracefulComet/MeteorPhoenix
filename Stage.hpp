#pragma once
#include "Textures.hpp"
#include <vector>
class Stage{
public:
    Stage()=default;
    ~Stage()= default;
    void init(SDL_Renderer* render);
    void saveStage(std::string FileName);
    void loadStage(std::string FileName);

    void update(SDL_Renderer* render);


private:

 //   std::vector<Tile> bg1;
    Tile Bg1[60][30];
};