#include "Window.h"
#include <iostream>

Window::Window()
{
    window = nullptr;
    renderer = nullptr;

}
    
Window::Window(const char* title, int width, int height)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("Inventory Management System", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (window == NULL)
    {
        std::cout << "Error: " << SDL_GetError() << std::endl;
        exit(-1);
    }

    SDL_Rect square;
    square.x = 320;
    square.y = 240;
    square.w = 50;
    square.h = 50;

    SDL_Event windowEvent;

    while (true)
    {
        if (SDL_PollEvent(&windowEvent))
        {
            if (SDL_QUIT == windowEvent.type)
            {
                break;
            }
            else if (SDL_KEYDOWN == windowEvent.type)
            {
                switch (windowEvent.key.keysym.sym)
                {
                    case SDLK_UP:
                        square.y -= 10;
                        break;
                    case SDLK_DOWN:
                        square.y += 10;
                        break;
                    case SDLK_LEFT:
                        square.x -= 10;
                        break;
                    case SDLK_RIGHT:
                        square.x += 10;
                        break;
                }
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderFillRect(renderer, &square);

        SDL_RenderPresent(renderer);
    }
}

Window::~Window()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

SDL_Window* Window::getWindow() const
{
    return window;
}

SDL_Renderer* Window::getRenderer() const
{
    return renderer;
}