#include "Props/Prop.h"
#include <SDL2/SDL.h>

Prop::Prop() {}

Prop::~Prop() {}

void Prop::draw() {}

void Prop::update() {}

void Prop::lateUpdate() {};

void Prop::removeFromGame() 
{
    
}

void Prop::destroy()
{
    ToRemove = true;

    IsActive = false;
    IsVisible = false;
}
