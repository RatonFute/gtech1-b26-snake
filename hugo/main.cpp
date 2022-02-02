#include "window.hpp"
#include "snake.hpp"
#include "segment.hpp"
#include "window.cpp"
#include "snake.cpp"
#include "segment.cpp"



#include <SDL2/SDL.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>




Game window;
int go = true;

int main(void){
    

    Snake *snake = new Snake(20,2);
    



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