#pragma once

#include "Engine/Scenes.h"
#include "Props/Sprite.h"
#include <string>

class TestScene : public Scene
{
    public:

    TestScene(std::string name);

    Sprite* Player;

    void updateScene() override;
    void loadScene() override;

    void unloadScene() override;

};