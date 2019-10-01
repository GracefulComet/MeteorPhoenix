#include"Textures.hpp"

Textures* Textures::s_pInstance = nullptr;

Textures* Textures::Instance(){
  if(s_pInstance == 0){
    s_pInstance = new Textures;
    s_pInstance->m_nextTextureID = 1;

  }
return s_pInstance;
}
bool Textures::Load(std::string FileName, SDL_Renderer* pRender)
{
//  SDL_Surface *pTempSurface = IMG_Load(FileName.c_str());
#ifndef __ANDROID__
std::string  Prefix = "assets/";
std::string filepath = Prefix + FileName;
  SDL_RWops* pfile = SDL_RWFromFile(filepath.c_str(), "r");
#endif
#ifdef __ANDROID__
  SDL_RWops* pfile = SDL_RWFromFile(FileName.c_str(), "r");
#endif

  SDL_Surface *pTempSurface = IMG_Load_RW(pfile, 1);
  if (pTempSurface == 0) {
    return false;
  
  }

  SDL_Texture *pTexture = SDL_CreateTextureFromSurface(pRender, pTempSurface);

  SDL_FreeSurface(pTempSurface);

  if (pTexture != 0) {

    if(GetTextureID(FileName) > 0){
    std::cout << FileName <<" file already Loaded " << std::endl << "re"; 
    }else{
    m_TextureidMap[FileName] = m_nextTextureID;

    m_TextureMap[m_nextTextureID] = pTexture;
    m_nextTextureID++;
    }
    return true;
  }

  return false;
}
unsigned int Textures::CheckedTextureLoad(std::string FileName,  SDL_Renderer* pRender){
      if (this->Load(FileName, pRender) == true) {
    std::cout << "loaded " << FileName << std::endl;
    return GetTextureID(FileName);
  } else {
    std::cout << "Failed to load " << FileName << std::endl;
    return 0;
  }
}
void Textures::draw(unsigned int Textureid, int xPos, int yPos, int width, int height,
              float xScale,float yScale, SDL_Renderer *pRender, SDL_RendererFlip flip) {
  SDL_Rect srcRect;
  SDL_Rect destRect;
  srcRect.x = 0;
  srcRect.y = 0;
  srcRect.w = destRect.w = (int)(width * xScale);
  srcRect.h = destRect.h = (int)(height * yScale);
  destRect.x = xPos;
  destRect.y = yPos;
  SDL_RenderCopyEx(pRender, m_TextureMap[Textureid], &srcRect, &destRect, 0, 0, flip);
}

void Textures::drawFrame(unsigned int Textureid, int xPos, int yPos, int width, int height,
                     int currentRow, int currentCol,float xScale ,float yScale , double rotAngle,
                     
                     SDL_Renderer *pRender, SDL_RendererFlip flip) {
  SDL_Rect srcRect;
  SDL_Rect destRect;
  srcRect.y = currentRow * width;
  srcRect.x = height * currentCol;
  srcRect.w = destRect.w = width;
  srcRect.h = destRect.h = height;
  destRect.x = xPos;
  destRect.y = yPos;
  destRect.w = (int)( width * xScale);
  destRect.h = (int)(height * yScale);
  SDL_RenderCopyEx(pRender, m_TextureMap[Textureid], &srcRect, &destRect, rotAngle,
                   NULL, flip);
}


unsigned int Textures::GetTextureID(std::string FileName){
  if (m_TextureidMap[FileName] > 0){
  return m_TextureidMap[FileName];}
  else{return 0;}
}

const TileSet LoadTileSet(std::string FileName , SDL_Renderer* Renderer){
  TileSet Export;



  std::string TextureFileName;
//  std::ifstream tileimport(FileName);
  SDL_RWops* pfile;
  pfile = SDL_RWFromFile(FileName.c_str(), "r");

  if(pfile != NULL){
    std::cout << "tilesetfile opened with RWops " << std::endl;
    char buffer[256];
    SDL_RWread(pfile,buffer, sizeof(buffer), 1);
    std::string tileimport = buffer;
    SDL_FreeRW(pfile);

    std::stringstream TileParce;
    TileParce << tileimport;
    TileParce >> TextureFileName >> Export.TileWidth >> Export.TileHeight >>Export.NumOfColums >> Export.NumOfRows;
    std::cout << "Loaded Tile Data from " << FileName <<std::endl;
    Export.TextureID = gfx2D::Instance()->CheckedTextureLoad(TextureFileName, Renderer);


  }   else{
    std::cout << "failed to load TileSet " << FileName << std::endl;
  }



  // if(tileimport.is_open()){
  
  // tileimport >>  TextureFileName >> Export.TileWidth >> 
  // Export.TileHeight >> Export.NumOfColums >> Export.NumOfRows;
  // std::cout << "Loaded Tile Data from " << FileName << std::endl;
  // tileimport.close();
 



  return  Export;
}

unsigned int Textures::GetTileSetID(std::string FileName){

  if(m_TileSetidMap[FileName] > 0){
    return m_TileSetidMap[FileName];
  }else{
    return 0;
  }
}

bool Textures::AddTileSet(std::string FileName, SDL_Renderer* render){

if(GetTileSetID(FileName) == 0){
TileSet TempTileset = LoadTileSet(FileName , render);
m_TileSetMap[m_nextTileID] = TempTileset;
m_TileSetidMap[FileName] = m_nextTileID;
m_nextTileID++;
return true;
}
if(GetTileSetID(FileName) > 0){
return false;
}
return false;
}

int Textures::getTCollums(unsigned int TilesetID){
return m_TileSetMap[TilesetID].NumOfColums;
}

int Textures::getTRows(unsigned int TilesetID){
return m_TileSetMap[TilesetID].NumOfRows;
}
int Textures::getHeight(unsigned int TilesetID){
  return m_TileSetMap[TilesetID].TileHeight;
}

int Textures::getWidth(unsigned int TilesetID){
  return m_TileSetMap[TilesetID].TileWidth;
}


void Textures::drawTile(Tile instance , SDL_Renderer* render){

drawFrame(m_TileSetMap[instance.TileSetid].TextureID, instance.xPos, instance.yPos, m_TileSetMap[instance.TileSetid].TileWidth,m_TileSetMap[instance.TileSetid].TileHeight, instance.currentRow , instance.currentCollum , instance.xScale, instance.yScale, instance.rotationAngle,render,instance.flip );

}
