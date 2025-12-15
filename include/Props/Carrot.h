#pragma once

#include "Props/Sprite.h"
#include "Utils/Vector2.h"
#include <SDL2/SDL.h>

class Carrot : public Sprite
{
    public:

    Vector2 Velocity;

    float Gravity = 10.5f;

    void start() override;
    void update() override;
    void draw() override;

    void removeFromGame() override;
    
    private:
    
    SDL_Texture* _normalTexture;
    SDL_Texture* _fallingTexture;
    SDL_Texture* _risingTexture;

    int _fallingWidth;
    int _fallingHeight;
    int _risingWidth;
    int _risingHeight;
    int _normalWidth;
    int _normalHeight;

};

