#include "Props/Prop.h"
#include <SDL2/SDL.h>
#include <memory>
#include <vector>
#include "Addons/Addon.h"

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
    ToRemove = true;
    
    IsActive = false;
    IsVisible = false;
}

void Prop::start() 
{
    _started = true;
}
