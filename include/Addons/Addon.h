#pragma once

#include "Props/Prop.h"

class WorldProp;

class Addon : public Prop 
{
    public: 

    WorldProp* Parent = nullptr;
};