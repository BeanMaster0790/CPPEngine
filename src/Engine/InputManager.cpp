#include <SDL2/SDL.h>
#include "Engine/InputManager.h"

void InputManager::updateKeys()
{
    const Uint8* keys = SDL_GetKeyboardState(NULL);

    for (int i = 0; i < 512; i++)
    {
        lastKeys[i] = currentKeys[i];
        currentKeys[i] = keys[i];
    }
    
}

bool InputManager::isKeyHeld(SDL_Scancode key)
{
    return currentKeys[key];
}

bool InputManager::wasKeyPressed(SDL_Scancode key)
{
    return !lastKeys[key] && currentKeys[key];
}

bool InputManager::wasKeyRelased(SDL_Scancode key)
{
    return lastKeys[key] && !currentKeys[key];
}