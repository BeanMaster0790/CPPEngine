#include "Props/Sprite.h"
#include "SDL2/SDL.h"
#include <SDL2/SDL_image.h>
#include <string>
#include "Engine/Engine.h"

void Sprite::draw() 
{
    SDL_Rect drawRect = {static_cast<int>(Position.X), static_cast<int>(Position.Y), _textureWidth, _textureHeight};
    SDL_RenderCopy(SDL_Engine::GameRenderer, Texture, nullptr, &drawRect);
}

void Sprite::loadTexture(std::string path)
{
    SDL_Log("Loading image %s", path.c_str());
    SDL_Surface* surf = IMG_Load(path.c_str());

    if(!surf)
    {
        SDL_Log("Image failed to load : %s e: %s", path.c_str(), IMG_GetError());
        Texture = nullptr;
    }

    Texture = SDL_CreateTextureFromSurface(SDL_Engine::GameRenderer, surf);
    SDL_FreeSurface(surf);

    if (!Texture) 
    {
        SDL_Log("Failed to create texture from %s: %s", path.c_str(), SDL_GetError());
        Texture = nullptr;
    }

    if(!Texture)
    {
        SDL_Log("WARNING! The loadTexture function failed to load a texture. Be preprated for unexpected issues!");
    }
    else
    {
        SDL_QueryTexture(Texture, nullptr, nullptr, &_textureWidth, &_textureHeight);
        SDL_Log("Image %s has been loaded", path.c_str());
    }
}

void Sprite::removeFromGame()
{
    SDL_DestroyTexture(Texture);
    Texture = nullptr;
}