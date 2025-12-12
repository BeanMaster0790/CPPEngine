#include "Props/Carrot.h"
#include "Engine/Engine.h"

void Carrot::update()
{
    Prop::update();

    Velocity.Y += Gravity;

    if(SDL_Engine::InputManagment->wasKeyPressed(SDL_SCANCODE_SPACE))
    {
        Velocity.Y = -250;
    }

    Position.Y += Velocity.Y * SDL_Engine::DeltaTime;
}

void Carrot::start()
{
    Prop::start();

    Position = Vector2(100, 100);

    loadTexture("assets/Textures/Carrot.png");

}

void Carrot::draw()
{
    Sprite::draw();
}