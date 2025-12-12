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

    void removeFromGame() override;

    protected:

    int _textureWidth;
    int _textureHeight;
};
