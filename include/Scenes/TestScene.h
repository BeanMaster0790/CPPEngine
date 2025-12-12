#pragma once

#include "Engine/Scenes.h"
#include "Props/Sprite.h"
#include "Props/Carrot.h"
#include <string>

class TestScene : public Scene
{
    public:

    TestScene(std::string name);

    Carrot* Player;

    void updateScene() override;
    void loadScene() override;

    void unloadScene() override;

};