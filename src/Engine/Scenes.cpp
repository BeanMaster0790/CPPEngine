#include <string>
#include <vector>
#include<memory>
#include <unordered_map>
#include <SDL2/SDL.h>
#include "Engine/Scenes.h"
#include "Props/Prop.h"
#include <algorithm>

Scene::Scene(std::string sceneName) : SceneName(sceneName) {}

void Scene::updateScene()
{
    for(auto& prop : _props)
    {
        if(!prop->PropScene)
        {
            prop->PropScene = this;
        }

        prop->update();
    }

    for(auto& prop : _props)
    {
        prop->lateUpdate();
    }

    _props.erase(std::remove_if(_props.begin(), _props.end(), [](const auto& prop){ return prop->ToRemove; }), _props.end());


}

void Scene::drawScene()
{
    for(auto& prop : _props)
    {
        prop->draw();
    }
}

void Scene::unloadScene()
{
    for(auto& prop : _props)
    {
        prop->removeFromGame();
    }

    _props.clear();

    IsLoaded = false;
}

void Scene::loadScene()
{
    IsLoaded = true;
}

SceneManager::~SceneManager()
{
    unloadAllScenes();
}

void SceneManager::loadScene(std::string name)
{
    SDL_Log("Loading scene %s...", name.c_str());

    if(_scenes[name]->IsLoaded)
    {
        SDL_Log("Scene %s has already been loaded. Aborting", name.c_str());
        return;
    }

    _scenes[name]->loadScene();

    SDL_Log("Scene %s has been loaded and can now be made active", name.c_str());
}

void SceneManager::unloadScene(std::string name)
{
    SDL_Log("Unloading scene %s...", name.c_str());

    if(!_scenes[name]->IsLoaded)
    {
        SDL_Log("Scene %s is currently not loaded. Aborting", name.c_str());
        return;
    }

    if(activeScene->SceneName == name)
    {
        SDL_Log("Scene %s is currently active. Aborting", name.c_str());
        return;
    }

    _scenes[name]->unloadScene();

    SDL_Log("Scene %s has been unloaded from memory", name.c_str());
}

void SceneManager::unloadAllScenes()
{
    activeScene = nullptr;

    for(auto& scene : _scenes)
    {
        unloadScene(scene.second.get()->SceneName);
    }
}

void SceneManager::setActiveScene(std::string name)
{
    

    SDL_Log("Setting scene %s as active...", name.c_str());

    if(!_scenes[name]->IsLoaded)
    {
        SDL_Log("Scene %s is currently not loaded. Aborting", name.c_str());
        return;
    }

    
    if(!activeScene)
    {
        activeScene = _scenes[name].get();
        
        SDL_Log("Scene %s has been set as active. ", name.c_str());
    }
    else
    {
        if(activeScene->SceneName == name)
        {
            SDL_Log("Scene %s is currently active. Aborting", name.c_str());
            return;
        }

        std::string lastScene = activeScene->SceneName;

        activeScene = _scenes[name].get();

        SDL_Log("Scene %s has been set as active. WARNING! The last active scene %s is still in memory. Use unloadScene if you don't need to save the state the scene was in before no longer being active.", name.c_str(), lastScene.c_str());
    }

}

void SceneManager::drawActiveScene() 
{
    if(!activeScene)
    {
        SDL_Log("WARNING! There is no active scene. Aborting");
        return;
    }

    activeScene->drawScene();
}

void SceneManager::updateActiveScene() 
{
    if(!activeScene)
    {
        SDL_Log("WARNING! There is no active scene. Aborting");
        return;
    }

    activeScene->updateScene();
}