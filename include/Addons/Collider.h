#pragma once

#include <SDL2/SDL.h>
#include "Addons/Addon.h"
#include "Engine/Event.h"

class Collider : public Addon
{
    public:

    Event<Collider&, SDL_Rect> OnCollision; 

    SDL_Rect ColliderRect;
    
    void start() override;

    void lateUpdate() override;
    
    void checkCollision(Collider& collider);

    void onCollide(Collider& collider, SDL_Rect intersectionRect);
};