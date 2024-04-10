#include "input/input.hpp"
#include <iostream> // for debugging, can be removed in final version

/* Input class
 * Keeps track of keyboard state
 */

// Reset all key states at the beginning of each frame
void Input::beginNewFrame() {
    _pressedKeys.clear();    // Clear the map of pressed keys
    _releasedKeys.clear();   // Clear the map of released keys
}

// Update key state when a key is pressed
void Input::keyDownEvent(const SDL_Event& event) {
    if (event.type == SDL_KEYDOWN) {    // Check if the event is a key down event
        _pressedKeys[event.key.keysym.scancode] = true;    // Set the corresponding key in the pressed keys map to true
        _heldKeys[event.key.keysym.scancode] = true;       // Set the corresponding key in the held keys map to true
    }
}

// Update key state when a key is released
void Input::keyUpEvent(const SDL_Event& event) {
    if (event.type == SDL_KEYUP) {  // Check if the event is a key up event
        _releasedKeys[event.key.keysym.scancode] = true;   // Set the corresponding key in the released keys map to true
        _heldKeys[event.key.keysym.scancode] = false;      // Set the corresponding key in the held keys map to false
    }
}

// Check if a key was pressed during the current frame
bool Input::wasKeyPressed(SDL_Scancode key) {
    return _pressedKeys[key];   // Return true if the key was pressed during the current frame
}

// Check if a key was released during the current frame
bool Input::wasKeyReleased(SDL_Scancode key) {
    return _releasedKeys[key];  // Return true if the key was released during the current frame
}

// Check if a key is currently being held
bool Input::isKeyHeld(SDL_Scancode key) {
    return _heldKeys[key];      // Return true if the key is currently being held
}

// Debugging function to print key states
void Input::printKeyStates() {
    std::cout << "Pressed keys:" << std::endl;
    for (auto const& [key, value] : _pressedKeys) {   // Iterate over the pressed keys map
        std::cout << SDL_GetScancodeName(key) << std::endl;  // Print the name of each pressed key
    }

    std::cout << "Released keys:" << std::endl;
    for (auto const& [key, value] : _releasedKeys) {  // Iterate over the released keys map
        std::cout << SDL_GetScancodeName(key) << std::endl;  // Print the name of each released key
    }

    std::cout << "Held keys:" << std::endl;
    for (auto const& [key, value] : _heldKeys) {   // Iterate over the held keys map
        std::cout << SDL_GetScancodeName(key) << std::endl;  // Print the name of each held key
    }
}
