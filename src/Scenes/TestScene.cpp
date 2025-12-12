#include "Scenes/TestScene.h"
#include "Engine/Engine.h"
#include <string>

TestScene::TestScene(std::string name) : Scene(name)
{

}

void TestScene::loadScene()
{
    Scene::loadScene();

    Player = &createProp<Sprite>();

    Player->Name = "Player";
    Player->Tag = "Player";

    Player->loadTexture("assets/Textures/Granny.png");

    Player->Position = Vector2(100,100);
}

void TestScene::updateScene()
{
    Scene::updateScene();

    if(SDL_Engine::InputManagment->isKeyHeld(SDL_SCANCODE_W))
    {
        Player->Position.Y -= 1;
    }
    else if (SDL_Engine::InputManagment->isKeyHeld(SDL_SCANCODE_S))
    {
        Player->Position.Y += 1;
    }

    if(SDL_Engine::InputManagment->isKeyHeld(SDL_SCANCODE_A))
    {
        Player->Position.X -= 1;
    }
    else if (SDL_Engine::InputManagment->isKeyHeld(SDL_SCANCODE_D))
    {
        Player->Position.X += 1;
    }
    
}

void TestScene::unloadScene()
{
    Scene::unloadScene();

    Player = nullptr;
}