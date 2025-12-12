#pragma once

#include <string>
#include <vector>
#include<memory>
#include <unordered_map>
#include <SDL2/SDL.h>
#include "Props/Prop.h"

class Scene
{
    public:

    std::string SceneName;

    bool IsLoaded = false;

    Scene(std::string sceneName);

    virtual void loadScene();

    virtual void unloadScene();

    virtual void updateScene();

    virtual void drawScene();

    template<typename T, typename... Args>
    T& createProp(Args&&... args)
    {
        auto prop = std::make_unique<T>(std::forward<Args>(args)...);

        T& propReference = *prop;

        _props.push_back(std::move(prop));

        return propReference;
    }

    protected:

    std::vector<std::unique_ptr<Prop>> _props;
};

class SceneManager
{
    public:

    ~SceneManager();

    Scene* activeScene = nullptr;

    template<typename T, typename... Args>
    T& createScene(const std::string& name, Args&&... args)
    {
        auto scene = std::make_unique<T>(std::forward<Args>(args)...);

        T& sceneReference = *scene;

        // Move raw pointer into a unique_ptr<Scene>
        _scenes[name] = std::unique_ptr<Scene>(scene.release());

        return sceneReference;
    }

    void loadScene(std::string sceneName);
    
    void unloadScene(std::string sceneName); 

    void unloadAllScenes();

    void setActiveScene(std::string sceneName);

    void updateActiveScene();

    void drawActiveScene();

    private:

    std::unordered_map<std::string, std::unique_ptr<Scene>> _scenes;

};