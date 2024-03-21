#include "screen.h"
#include <iostream>

Screen::Screen()
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(640*1.5, 480*1.5, 0, &window, &renderer);
    SDL_RenderSetScale(renderer, 2,2);
}

void Screen::pixel(float x, float y)
{
    points.emplace_back(SDL_FPoint{x, y});
}

void Screen::show()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    for(auto& point : points)
    {
        SDL_RenderDrawPointF(renderer, point.x, point.y);
    }

    SDL_RenderPresent(renderer);
}
void Screen::clear()
{
    points.clear();
}
void Screen::input()
{
    SDL_Event e;
    while(SDL_PollEvent(&e))
    {
        if(e.type == SDL_QUIT)
        {
            SDL_DestroyRenderer(renderer);
            SDL_DestroyWindow(window);
            SDL_Quit();
            exit(0);
        }
    }
}
