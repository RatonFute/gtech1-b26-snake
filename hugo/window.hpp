#pragma once
#include <SDL2/SDL.h>

class MainSDLWindow{
    public:  
        MainSDLWindow();
        ~MainSDLWindow();
        int init(const char* title, int x, int y, int width, int height, int a);
        void update();
        void clean();
        SDL_Renderer* getRenderer();
        bool running();

    private:
        bool isRunning = true;
        SDL_Renderer* renderer;
        SDL_Window* window;  //Déclaration de la fenêtre
}; 
