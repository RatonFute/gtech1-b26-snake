#include "window.hpp"
#include "snake.hpp"
#include "window.cpp"
#include "snake.cpp"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#define PAS 10
#define SIZE 20


int go = true;

int main(void){
    

    Snake *snake = new Snake(SIZE,2);
    MainSDLWindow window;



    while (go == true)
    {   
        
        
        snake->move();

        const Uint8 *Keystates = SDL_GetKeyboardState(NULL);
        if (Keystates[SDL_SCANCODE_UP]) 
        {
            snake->turn(0);
            snake->move();
        }
        if (Keystates[SDL_SCANCODE_DOWN]) 
        {
            snake->turn(1);
            snake->move();
        }
        if (Keystates[SDL_SCANCODE_RIGHT]) 
        {
            snake->turn(2);
            snake->move();
        }
        if (Keystates[SDL_SCANCODE_LEFT]) 
        {
            snake->turn(3);
            snake->move();
        }

    
        
        // Get the next event
        SDL_Event event;
        if (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
            window.clean();
            break;
            }
        }
        SDL_Delay(50);
    }  
    
    return 0;
}