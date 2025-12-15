#pragma once

#include <string>
#include <SDL2/SDL.h>
#include <vector>
#include <memory>
#include <unordered_map>
#include <functional>

class Scene;

class Prop
{
    public: 

    std::string Name ="None";
    std::string Tag = "None";

    bool IsVisible = true;
    bool IsActive = true;
    
    bool ToRemove = false;

    Scene*  PropScene =  nullptr;

    Prop();
    
    virtual ~Prop();

    virtual void start();

    virtual void draw();

    virtual void update();

    virtual void lateUpdate();

    virtual void removeFromGame();

    protected:

    bool _started = false;

};