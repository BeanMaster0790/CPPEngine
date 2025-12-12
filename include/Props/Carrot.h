#pragma once

#include "Props/Sprite.h"
#include "Utils/Vector2.h"

class Carrot : public Sprite
{
    public:

    Vector2 Velocity;

    float Gravity = 8.5f;

    void start() override;
    void update() override;
    void draw() override;
};

