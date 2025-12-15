#pragma once

#include <SDL2/SDL.h>
#include "Props/Pipe.h"
#include "Props/Prop.h"
#include "Addons/Collider.h"

class PipeManager : public Prop
{
    private:

    Pipe* _topFirstPipe;
    Pipe* _bottomFirstPipe;


    Pipe* _topSecondPipe;
    Pipe* _bottomSecondPipe;

    public:

    float PipeMoveSpeed = -170;

    void start() override;

    void update() override;

    void onCollide();
};