#include "Engine.h"
#include <iostream>
#include <stdexcept>

Engine::Engine(const std::string& title, int width, int height,
    const std::string& fontPath, int fontSize, const std::string& soundPath)
    : window(nullptr), renderer(nullptr)
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: "
            << SDL_GetError() << std::endl;
        throw std::runtime_error("SDL_Init failed");
    }


    window = SDL_CreateWindow(title.c_str(),
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        width, height, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Window could not be created! SDL_Error: "
            << SDL_GetError() << std::endl;
        SDL_Quit();
        throw std::runtime_error("SDL_CreateWindow failed");
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Renderer could not be created! SDL_Error: "
            << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        throw std::runtime_error("SDL_CreateRenderer failed");
    }

}


Engine::~Engine()
{
    if (renderer)
        SDL_DestroyRenderer(renderer);
    if (window)
        SDL_DestroyWindow(window);
    SDL_Quit();
}


void Engine::drawCircle(int centerX, int centerY, int radius,
    SDL_Color color)
{
    filledCircleRGBA(renderer, centerX, centerY, radius, color.r, color.g, color.b, color.a);
    aacircleRGBA(renderer, centerX, centerY, radius, color.r, color.g, color.b, color.a);
}

void Engine::drawRectangle(int centerX, int centerY, int rectWidth, int rectHeight,
    SDL_Color color)
{
    SDL_Rect rect;
    rect.x = centerX - rectWidth / 2;
    rect.y = centerY - rectHeight / 2;
    rect.w = rectWidth;
    rect.h = rectHeight;

    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &rect);
}

void Engine::drawLine(int x1, int y1, int x2, int y2, SDL_Color color) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}

void Engine::clear(SDL_Color color)
{
    // Clear screen (set background to black).
    SDL_SetRenderDrawColor(getRenderer(), color.r, color.g, color.b, color.a);
    SDL_RenderClear(getRenderer());
}
void Engine::flip()
{

    SDL_RenderPresent(getRenderer());
}

SDL_Renderer* Engine::getRenderer() const {
    return renderer;
}


