#include "Scenes/TestScene.h"
#include "Engine/Engine.h"
#include <string>

TestScene::TestScene(std::string name) : Scene(name)
{

}

void TestScene::loadScene()
{
    Scene::loadScene();

    Player = &createProp<Carrot>();

    Player->Name = "Player";
    Player->Tag = "Player";
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