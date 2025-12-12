#include <SDL2/SDL.h>
#include <vector>
#include <memory>
#include <iostream>
#include "Engine/Engine.h"
#include "Engine/Scenes.h"
#include "Scenes/TestScene.h"
#include "Engine/InputManager.h"

SDL_Renderer* SDL_Engine::GameRenderer = nullptr;
std::unique_ptr<SceneManager> SDL_Engine::SceneManagment = nullptr;
std::unique_ptr<InputManager> SDL_Engine::InputManagment = nullptr;

float SDL_Engine::DeltaTime = 0;



int SDL_Engine::initalizeEngine()
{
    std::cout << "Starting SDL2...";
    if (SDL_Init(SDL_INIT_VIDEO) != 0) 
    {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Log("Creating Window");
    _gameWindow = SDL_CreateWindow("SDL2 Test", 100, 100, 800, 600, SDL_WINDOW_SHOWN);

    if (!_gameWindow)
    {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Log("Creating Renderer");
    GameRenderer = SDL_CreateRenderer(_gameWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
    if (!GameRenderer)
    {
        SDL_DestroyWindow(_gameWindow);
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Log("Creating SceneManager");
    SceneManagment = std::make_unique<SceneManager>();

    SDL_Log("Creating InputManager");
    InputManagment = std::make_unique<InputManager>();


    return startUpdateCycle();

}

int SDL_Engine::startUpdateCycle()
{
    SDL_Event e;

    SDL_Log("Creating demo Scene");
    TestScene& testScene = SceneManagment->createScene<TestScene>("Test", "Test");

    SceneManagment->loadScene("Test");
    SceneManagment->setActiveScene("Test");

    Uint64 lastTime = SDL_GetTicks64(); 

    while (IsRunning)
    {
        Uint64 currentTime = SDL_GetTicks64();

        Uint64 miliseondsPassed = currentTime - lastTime;

        DeltaTime = miliseondsPassed / 1000.0f;

        lastTime = currentTime;

        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                IsRunning = false;
            }
        }

        SDL_RenderPresent(GameRenderer);
        SDL_SetRenderDrawColor(GameRenderer, 0, 0, 0, 255);
        SDL_RenderClear(GameRenderer);

        InputManagment->updateKeys();

        update();
        draw();

    }

    std::cout << "Destroying all scenes";
    SceneManagment->unloadAllScenes();

    std::cout << "Destroying Renderer";
    SDL_DestroyRenderer(GameRenderer);

    std::cout << "Destroying Window";
    SDL_DestroyWindow(_gameWindow);

    std::cout << "Quitting";
    SDL_Quit();
    return 0;
}

void SDL_Engine::update()
{
    SceneManagment.get()->activeScene->updateScene();
}

void SDL_Engine::draw()
{
    SceneManagment.get()->activeScene->drawScene();
}