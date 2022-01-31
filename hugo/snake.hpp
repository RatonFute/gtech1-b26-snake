#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#ifndef EXERCICE1_HPP
#define EXERCICE1_HPP

class MainSDLWindow{
    public:

        MainSDLWindow(void);
        ~MainSDLWindow(void);         
        int init(void);
        int game(void);
        //int getRenderer(void);
        

    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        bool Game{true};
        bool lose{false};
};

/*class Snake{
    public:
    int x;
    int y;
};*/

 #endif