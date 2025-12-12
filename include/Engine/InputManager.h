#pragma once

#include <SDL2/SDL.h>

class InputManager
{
    public:

        bool isKeyHeld(SDL_Scancode key);
        bool wasKeyPressed(SDL_Scancode key);
        bool wasKeyRelased(SDL_Scancode key);

        void updateKeys();

    private:

    Uint8 currentKeys[512] = {0};
    Uint8 lastKeys[512] = {0}; 
};