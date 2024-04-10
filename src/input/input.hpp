#pragma once
#ifndef INPUT_H
#define INPUT_H

#include <SDL2/SDL.h>
#include <unordered_map> // Changed from <map> to <unordered_map>

class Input {
public:
    void beginNewFrame();
    void keyUpEvent(const SDL_Event& event);
    void keyDownEvent(const SDL_Event& event);
    void printKeyStates();
    
    bool wasKeyPressed(SDL_Scancode key);
    bool wasKeyReleased(SDL_Scancode key);
    bool isKeyHeld(SDL_Scancode key);

private:
    std::unordered_map<SDL_Scancode, bool> _heldKeys;     // Changed to unordered_map for better performance
    std::unordered_map<SDL_Scancode, bool> _pressedKeys;  // Changed to unordered_map for better performance
    std::unordered_map<SDL_Scancode, bool> _releasedKeys; // Changed to unordered_map for better performance
};

#endif
