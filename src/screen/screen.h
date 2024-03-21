#pragma once
#include <SDL2/SDL.h>
#include <vector>

class Screen 
{
public:
    Screen();
    void pixel(float x, float y);
    void show();
    void clear();
    void input();
    
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    std::vector<SDL_FPoint> points;
};
