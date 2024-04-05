#pragma once
#include <SDL2/SDL.h>
#include <vector>

struct SDL_Window;
struct SDL_Renderer;

class Graphics 
{
public:
    Graphics();
    void pixel(float x, float y);
    void show();
    void clear();
    void input();
    void run();

private:
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    std::vector<SDL_FPoint> points;
    bool shouldQuit = false;

    void toggleFullscreen();
};
