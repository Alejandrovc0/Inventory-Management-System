#ifndef WINDOW_h
#define WINDOW_h

#include <SDL2/SDL.h>

class Window
{
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;

    public:
        Window(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
        ~Window();
};


#endif