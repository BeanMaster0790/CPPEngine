#pragma once

#include "Props/Sprite.h"
#include "Addons/Collider.h"
#include <SDL2/SDL.h>

class PipeManager;

class Pipe : public Sprite
{
    public:

    PipeManager* Manager;

    void start() override;

    void update() override;

    void removeFromGame() override;

    void onCollide(Collider& collider, SDL_Rect rect);

    Pipe(bool upsideDown, PipeManager* manager);

    private:

    bool _upsideDown;


};


