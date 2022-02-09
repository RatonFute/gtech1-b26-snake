
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
    snake->spawn(50,50,2);
    while (play == true)
    {   
        

        snake->move();
        const Uint8 *state = SDL_GetKeyboardState(NULL);
        if (state[SDL_SCANCODE_UP]) 
        {
            
            snake->turn(0);

        }
        if (state[SDL_SCANCODE_DOWN]) 
        {
            
            snake->turn(1);
  
        }
        if (state[SDL_SCANCODE_RIGHT]) 
        {
            
            snake->turn(2);

        }
        if (state[SDL_SCANCODE_LEFT]) 
        {
            
            snake->turn(3);

        }
        
        SDL_SetRenderDrawColor(window.getRenderer(),0,0,0,SDL_ALPHA_OPAQUE);
        SDL_RenderClear(window.getRenderer());
        SDL_SetRenderDrawColor(window.getRenderer(),255,255,255,SDL_ALPHA_OPAQUE);
        snake->draw(window.getRenderer());
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
        SDL_Delay(20);
        

        
    }  
    
    return 0;
}