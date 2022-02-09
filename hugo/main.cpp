
#include <iostream>
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "window.hpp"
#include "snake.hpp"
#include "fruit.hpp"

#define WINDOWSIZE 600
#define SIZE 20
#define STARTDIR 2

int play = true;

int main(void){
    
    
    MainSDLWindow window;
    Snake *snake =new Snake(SIZE,STARTDIR);
    Fruit *fruit = new Fruit();
    window.init("Snake" , SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED , WINDOWSIZE , WINDOWSIZE, 0);
    snake->spawn(SIZE,SIZE,2);
    fruit->spawn(WINDOWSIZE,SIZE);
    while (play == true)
    {   
        

        snake->move();
        const Uint8 *state = SDL_GetKeyboardState(NULL);
        if (state[SDL_SCANCODE_Q]) 
        {
            snake->addsegment();
        }
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
        fruit->draw(window.getRenderer(),SIZE);
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