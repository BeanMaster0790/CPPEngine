#pragma once

#include "Props/WorldProp.h"
#include "SDL2/SDL.h"
#include "string"

class Sprite : public WorldProp
{
    public: 
    
    SDL_Texture* Texture = nullptr;

    void draw() override;

    void loadTexture(std::string path);

    static void loadTexture(std::string path, SDL_Texture*& texture, int* texWidth, int* texHeight);

    void removeFromGame() override;
};
