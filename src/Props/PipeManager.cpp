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
    _topFirstPipe->Position = Vector2(400, _baseTopPipePos);
    _bottomFirstPipe->Position = Vector2(400, _baseBottomPipePos);
    _topSecondPipe->Position = Vector2(800, _baseTopPipePos);
    _bottomSecondPipe->Position = Vector2(800, _baseBottomPipePos);

    srand(time(0));
}

void PipeManager::update() 
{
    Prop::update();

    if(_topFirstPipe->Position.X < -128)
    {
        _topFirstPipe->Position.X = 800;
        _bottomFirstPipe->Position.X = 800;

        int randomYOffset = rand() % 100;

        if(rand() % 2 == 0)
        {
            _topFirstPipe->Position.Y = _baseTopPipePos + randomYOffset;
            _bottomFirstPipe->Position.Y = _baseBottomPipePos + randomYOffset;

        }
        else
        {
            _topFirstPipe->Position.Y = _baseTopPipePos - randomYOffset;
            _bottomFirstPipe->Position.Y = _baseBottomPipePos - randomYOffset;
        }
    }

    if(_topSecondPipe->Position.X < -128)
    {
        _topSecondPipe->Position.X = 800;
        _bottomSecondPipe->Position.X = 800;

        int randomYOffset = rand() % 250;

        if(rand() % 2 == 0)
        {
            _topSecondPipe->Position.Y = _baseTopPipePos + randomYOffset;
            _bottomSecondPipe->Position.Y = _baseBottomPipePos + randomYOffset;

        }
        else
        {
            _topSecondPipe->Position.Y = _baseTopPipePos - randomYOffset;
            _bottomSecondPipe->Position.Y = _baseBottomPipePos - randomYOffset;
        }
    }
}

void PipeManager::onCollide()
{
    SDL_Log("I hit sommet");
}