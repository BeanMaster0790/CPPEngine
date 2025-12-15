#include "Props/PipeManager.h"
#include "Props/Pipe.h"
#include "Props/Prop.h"
#include "Engine/Scenes.h"

void PipeManager::start()
{
    Prop::start();

    SDL_Log("Creating Pipes...");
    _topFirstPipe = &PropScene->createProp<Pipe>(false, this);
    _bottomFirstPipe = &PropScene->createProp<Pipe>(true, this);
    _topSecondPipe = &PropScene->createProp<Pipe>(false, this);
    _bottomSecondPipe = &PropScene->createProp<Pipe>(true, this);

    SDL_Log("Setting Positions...");
    _topFirstPipe->Position = Vector2(400, 0);
    _bottomFirstPipe->Position = Vector2(400, 520);
    _topSecondPipe->Position = Vector2(800, 0);
    _bottomSecondPipe->Position = Vector2(800, 520);
}

void PipeManager::update() 
{
    Prop::update();

    if(_topFirstPipe->Position.X < -128)
    {
        _topFirstPipe->Position.X = 800;
        _bottomFirstPipe->Position.X = 800;
    }

    if(_topSecondPipe->Position.X < -128)
    {
        _topSecondPipe->Position.X = 800;
        _bottomSecondPipe->Position.X = 800;
    }
}

void PipeManager::onCollide()
{
    SDL_Log("I hit sommet");
}