
#include <iostream>
#include "window.hpp"
#include "snake.hpp"

#define SIZE 20
#define STARTDIR 2

int play = true;

int main(void){
    
    
    MainSDLWindow window;
    Snake *snake =new Snake(SIZE,STARTDIR);
    window.init();
    
    while (play == true)
    {   
      
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
        window.update();
        
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