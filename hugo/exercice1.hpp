#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#ifndef EXERCICE1_HPP
#define EXERCICE1_HPP

class MainSDLWindow{
    public:

        MainSDLWindow(void);
        ~MainSDLWindow(void);         
        int init(void);                                                 //initiate the window, check errors
        int game(int frame_rate_ms, int snake_speed_fpc);               //Game loop, calculate and draw
        //int getRenderer(void);
        

    private:
        //window management
        SDL_Window* window;
        SDL_Renderer* renderer;
        //Game loop management
        bool Game{true};
        bool Lose{false};
        SDL_Event event;
        //Frame rate management
        
};

/*class Snake{
    public:
    int x;
    int y;
};*/

 #endif