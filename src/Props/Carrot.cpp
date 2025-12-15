#include "Props/Carrot.h"
#include "Engine/Engine.h"
#include "Addons/Collider.h"

void Carrot::update()
{
    Sprite::update();

    Velocity.Y += Gravity;

    if(SDL_Engine::InputManagment->wasKeyPressed(SDL_SCANCODE_SPACE))
    {
        Velocity.Y = -400;
    }

    Position.Y += Velocity.Y * SDL_Engine::DeltaTime;
}

void Carrot::start()
{
    Sprite::start();

    Position = Vector2(50, 100);

    Sprite::loadTexture("assets/Textures/FallingCarrot.png", _fallingTexture, &_fallingWidth, &_fallingHeight);
    Sprite::loadTexture("assets/Textures/RisingCarrot.png", _risingTexture, &_risingWidth, &_risingHeight);
    Sprite::loadTexture("assets/Textures/Carrot.png", _normalTexture, &_normalWidth, &_normalHeight);

    Collider& collider = createAddon<Collider>();
}

void Carrot::draw()
{
    if(Velocity.Y < -20)
    {
        Height = _risingWidth;
        Width = _risingHeight;
        Texture = _risingTexture;
    }
    else if(Velocity.Y > 20)
    {
        Height = _fallingWidth;
        Width = _fallingHeight;
        Texture = _fallingTexture;
    }
    else
    {
        Height = _normalWidth;
        Width = _normalWidth;
        Texture = _normalTexture;
    }

    Sprite::draw();
}

void Carrot::removeFromGame()
{
    SDL_DestroyTexture(_fallingTexture);
    _fallingTexture = nullptr;
    SDL_DestroyTexture(_risingTexture);
    _risingTexture = nullptr;
    SDL_DestroyTexture(_normalTexture);
    _normalTexture = nullptr;

    Texture = nullptr;
}