#include "Props/Prop.h"
#include <SDL2/SDL.h>

Prop::Prop() {}

Prop::~Prop() {}

void Prop::draw() {}

void Prop::update() 
{
    if(!_started)
    {
        start();
    }
}

void Prop::lateUpdate() {};

void Prop::removeFromGame() 
{
    
}

void Prop::start() 
{
    _started = true;
}


void Prop::destroy()
{
    ToRemove = true;

    IsActive = false;
    IsVisible = false;
}
