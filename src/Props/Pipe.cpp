#include "Props/PipeManager.h"
#include "Props/Sprite.h"
#include "Engine/Engine.h"
#include "Addons/Collider.h"

void Pipe::start()
{
    Sprite::start();

    if(_upsideDown)
    {
        loadTexture("assets/Textures/PipeBottom.png");
    }
    else
    {
        loadTexture("assets/Textures/PipeTop.png");
    }

    Width *= 2;
    Height *= 1.5f;

    Collider& collider = createAddon<Collider>();

    collider.OnCollision.subscribe([this](Collider& col, SDL_Rect rec){Manager->onCollide();});
}

void Pipe::update()
{
    Sprite::update();

    Position.X += Manager->PipeMoveSpeed * SDL_Engine::DeltaTime;
}

void Pipe::removeFromGame()
{
    Sprite::removeFromGame();

    Manager = nullptr;
}

Pipe::Pipe(bool upsideDown, PipeManager* manager) : _upsideDown(upsideDown), Manager(manager) 
{
    SDL_Log("Pipe Constructed");
}