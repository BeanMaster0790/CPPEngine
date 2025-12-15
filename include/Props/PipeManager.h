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

    int _baseTopPipePos = 0;
    int _baseBottomPipePos = 520;

    public:

    float PipeMoveSpeed = -250;

    void start() override;

    void update() override;

    void onCollide();
};