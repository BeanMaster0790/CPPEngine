#include "Scenes/TestScene.h"
#include "Engine/Engine.h"
#include "Props/PipeManager.h"
#include <string>

TestScene::TestScene(std::string name) : Scene(name)
{

}

void TestScene::loadScene()
{
    Scene::loadScene();

    SDL_Log("Creating Player...");
    Player = &createProp<Carrot>();

    Player->Name = "Player";
    Player->Tag = "Player";

    SDL_Log("Creating PipeManager...");
    createProp<PipeManager>();
}

void TestScene::updateScene()
{
    Scene::updateScene();
}

void TestScene::unloadScene()
{
    Scene::unloadScene();

    Player = nullptr;
}