#include "Headers.h"

#include <iostream>

Window::Window(const char* title, int width, int height)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (window == NULL)
    {
        std::cout << "Window creation error: " << SDL_GetError() << std::endl;
        exit(-1);
    }

    SDL_Rect button;
    button.x = 960;
    button.y = 980;
    button.w = 85;
    button.h = 50;

    char* text;
    char* composition;
    int cursor;
    int selection_len;

    bool isRunning = true;

    SDL_Event windowEvent;

    while (isRunning)
    {
        if (SDL_PollEvent(&windowEvent))
        {
            if (SDL_QUIT == windowEvent.type)
            {
                isRunning = false;
            }
            else if (SDL_MOUSEBUTTONDOWN == windowEvent.type)
            {
                if (windowEvent.button.x >= button.x && windowEvent.button.x <= (button.x + button.w) && windowEvent.button.y >= button.y && windowEvent.button.y <= (button.y + button.h))
                {
                    std::cout << "Button clicked" << std::endl;
                }
                if (windowEvent.button.clicks == 2)
                {
                    
                }
                else if (windowEvent.button.clicks == 3)
                {
                   
                }
                switch (windowEvent.button.button)
                {
                    case SDL_BUTTON_LEFT:
                        button.x = windowEvent.button.x;
                        button.y = windowEvent.button.y;
                        break;
                    
                    case SDLK_ESCAPE:
                        isRunning = false;
                        break;
                }
            }
            else if (SDL_KEYDOWN == windowEvent.type)
            {
                switch (windowEvent.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    isRunning = false;
                    break;
                /*
                case SDLK_UP:
                    button.y -= 20;
                    break;
                case SDLK_DOWN:
                    button.y += 20;
                    break;
                case SDLK_LEFT:
                    button.x -= 20;
                    break;
                case SDLK_RIGHT:
                    button.x += 20;
                    break;
                */
                }
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderFillRect(renderer, &button);

        SDL_RenderPresent(renderer);
    }
}

Window::~Window()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

SDL_Window *Window::getWindow() const
{
    return window;
}

SDL_Renderer *Window::getRenderer() const
{
    return renderer;
}


void Window::setUserWindow(User &user, Accounts &accounts, std::string &name, std::string &username, std::string &password, int verificationCode)
{
    window = SDL_CreateWindow("User", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, SDL_WINDOW_SHOWN);
}



void setItemWindow(User &user, int serialNumber, std::string &name, int quantity, double price)
{

}