#pragma once

#include "Props/Prop.h"
#include "Utils/Vector2.h"

class WorldProp : public Prop
{
    public:

    Vector2 Position;

    int Layer = 0;

    float Rotation = 0;

    float Scale = 1;
};
