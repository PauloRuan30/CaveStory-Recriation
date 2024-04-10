#include <graphics/graphics.hpp>
#include <iostream>

// Largura e altura padrão da janela
int width = 1280;
int height = 720;

// Construtor da classe Graphics
Graphics::Graphics()
{
    // Inicializa o SDL para vídeo
    SDL_Init(SDL_INIT_VIDEO);

    // Cria uma janela e um renderer
    this->window = SDL_CreateWindow("CaveStory Remake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (!this->window) {
        std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
        exit(1);
    }

    this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!this->renderer) {
        std::cerr << "Failed to create renderer: " << SDL_GetError() << std::endl;
        exit(1);
    }

    // Define o título da janela
    SDL_SetWindowTitle(this->window, "CaveStory Remake");

    // Define a escala do renderer
    SDL_RenderSetLogicalSize(renderer, width, height);
}

// Adiciona um ponto à lista de pontos a serem desenhados
void Graphics::pixel(float x, float y)
{
    points.emplace_back(SDL_FPoint{x, y});
}

// Renderiza os pontos na tela
void Graphics::show()
{
    // Limpa a tela
    SDL_SetRenderDrawColor(renderer, 27, 18, 18, 255);
    SDL_RenderClear(renderer);

    // Define a cor para os pontos
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    // Desenha cada ponto na tela
    for (auto &point : points)
    {
        SDL_RenderDrawPointF(renderer, point.x, point.y);
    }

    // Atualiza a tela
    SDL_RenderPresent(renderer);
}

// Limpa a lista de pontos
void Graphics::clear()
{
    points.clear();
}

// Alterna entre tela cheia e modo janela
void Graphics::toggleFullscreen()
{
    Uint32 fullscreenFlag = SDL_WINDOW_FULLSCREEN;
    bool isFullscreen = SDL_GetWindowFlags(window) & fullscreenFlag;
    SDL_SetWindowFullscreen(window, isFullscreen ? 0 : fullscreenFlag);
}