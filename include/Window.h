#ifndef WINDOW_h
#define WINDOW_h

#include <SDL2/SDL.h>

class Window
{
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;

    public:
        Window(const char* title, int width, int height);
        ~Window();

        SDL_Window* getWindow() const;
        SDL_Renderer* getRenderer() const;

        void setUserWindow(User &user, Accounts &accounts, std::string &name, std::string &username, std::string &password, int verificationCode);
        void setItemWindow(User &user, int serialNumber, std::string &name, int quantity, double price);
};

#endif