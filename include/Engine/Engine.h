#pragma once

#include <SDL2/SDL.h>
#include <vector>
#include <memory>
#include "Engine/Engine.h"
#include "Engine/InputManager.h"
#include "Engine/Scenes.h"

class SDL_Engine
{
    private:

    SDL_Window* _gameWindow = nullptr;

    
    //Starts a while loop and calls each of the core game loops as long as the "IsRunning" variable is true
    int startUpdateCycle();
    //Grabs the users inputs then passes them into the input manager for other classes to use.
    //int handleInput();
    //Updates the current scene.
    void update();
    //Draws the current scene.
    void draw();
    
    
    public:
    
    static float DeltaTime;

    static SDL_Renderer* GameRenderer;

    //Controls if the update loop should still run
    bool IsRunning = true;

    //Handles loading, unloading, updating and drwaing scenes
    static std::unique_ptr<SceneManager> SceneManagment;

    //Simplifies input into a few functions like "wasKeyPressed()", "isKeyHeld()"
    static std::unique_ptr<InputManager> InputManagment;
    
    //Loads the window and creates the renderer
    int initalizeEngine();

    //Handles unloading the entire game before closing to prevent memory still being used when the game is closed.
    int quit();



};