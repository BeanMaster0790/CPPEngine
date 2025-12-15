#include "Addons/Collider.h"
#include "Props/WorldProp.h"

void Collider::start()
{
    Addon::start();
}

void Collider::lateUpdate()
{

    Addon::lateUpdate();

    if(!Parent)
        return;

    ColliderRect.x = Parent->Position.X;
    ColliderRect.y = Parent->Position.Y;

    ColliderRect.w = Parent->Width;
    ColliderRect.h = Parent->Height;
}

void Collider::checkCollision(Collider& collider)
{
    SDL_Rect intersectRect;

    if(SDL_IntersectRect(&ColliderRect, &collider.ColliderRect, &intersectRect))
    {
        onCollide(collider, intersectRect);
        collider.onCollide(*this, intersectRect);
    }
}

void Collider::onCollide(Collider& collider, SDL_Rect intersectionRect)
{
    OnCollision.trigger(collider, intersectionRect);
}