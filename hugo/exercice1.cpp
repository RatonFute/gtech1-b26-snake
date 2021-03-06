#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "exercice1.hpp"



int MainSDLWindow::init()
{
     
    if(SDL_VideoInit(NULL) < 0)
    {
        printf("Fail :%s",SDL_GetError());
        return EXIT_FAILURE;
    }
    
     // Création de la fenêtre :
    window = SDL_CreateWindow("Snakee" , SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED , 600 , 600, 0);
    if(window == NULL) 
    {
        printf("Erreur lors de la creation d'une fenetre : %s",SDL_GetError());
        return EXIT_FAILURE;
    }
    // création du renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC); 
    if(renderer == NULL)
    {
        printf("Erreur lors de la creation d'un renderer : %s",SDL_GetError());
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int MainSDLWindow::game(int frame_rate_ms, int snake_speed_fpc){
    int x;
    int y;
    int incrx=1;
    int incry=0;
    SDL_Rect rectangle = {x,y,20,20};
        
    int frame_delay;
    Uint32 frame_start;

    // Start the main game loop:
    Uint32 iter = 0;
    do {
        // Begin of current frame:
        frame_start = SDL_GetTicks();

        // Check for pressed keyboard keys:  <--- IMPORTANT: Le claier est toujours "lu" à 50Hz!
        const Uint8 *keystates = SDL_GetKeyboardState(NULL);

        if (keystates[SDL_SCANCODE_UP]) {
            incrx=0;
            incry=-1;
            
        }
        if (keystates[SDL_SCANCODE_DOWN]) {
            incrx=0;
            incry=1;
            
        }
        if (keystates[SDL_SCANCODE_LEFT]) {
            incry=0;
            incrx=-1;
            
        }
        if (keystates[SDL_SCANCODE_RIGHT]) {
            incry=0;
            incrx=1;
            
        }

        // Make the game to evolve / snake to move, only every =snake_speed_fpc= frames:
        if (iter % snake_speed_fpc == 0) {
        // Next iteration of the game:
            
            rectangle.x=rectangle.x + incrx;
            rectangle.y=rectangle.y + incry;

            if(rectangle.x>580 || rectangle.x<0 || rectangle.y>580 || rectangle.y<0){
                Lose=true;
            }

            
        }

        // Render the game:
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_RenderFillRect(renderer, &rectangle);
        
        SDL_RenderPresent(renderer);
        SDL_Delay(30);  

        if (Lose){
                SDL_Rect D1 = {70,200,20,90};
                SDL_Rect D2 = {70,200,50,20};
                SDL_Rect D3 = {70,270,50,20};
                SDL_Rect D4 = {120,220,20,50};
                SDL_Rect E1 = {150,200,20,90};
                SDL_Rect E2 = {150,200,50,20};
                SDL_Rect E3 = {150,235,50,20};
                SDL_Rect E4 = {150,270,50,20};
                SDL_Rect A1 = {210,220,20,70};
                SDL_Rect A2 = {250,220,20,70};
                SDL_Rect A3 = {230,200,20,20};
                SDL_Rect A4 = {230,240,20,20};
                SDL_Rect D11 = {280,200,20,90};
                SDL_Rect D12 = {280,200,50,20};
                SDL_Rect D13 = {280,270,50,20};
                SDL_Rect D14 = {330,220,20,50};


                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
                SDL_RenderClear(renderer);

                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
                SDL_RenderFillRect(renderer, &rectangle);

                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
                SDL_RenderFillRect(renderer, &D1);
                SDL_RenderFillRect(renderer, &D2);
                SDL_RenderFillRect(renderer, &D3);
                SDL_RenderFillRect(renderer, &D4);
                SDL_RenderFillRect(renderer, &E1);
                SDL_RenderFillRect(renderer, &E2);
                SDL_RenderFillRect(renderer, &E3);
                SDL_RenderFillRect(renderer, &E4);
                SDL_RenderFillRect(renderer, &A1);
                SDL_RenderFillRect(renderer, &A2);
                SDL_RenderFillRect(renderer, &A3);
                SDL_RenderFillRect(renderer, &A4);
                SDL_RenderFillRect(renderer, &D11);
                SDL_RenderFillRect(renderer, &D12);
                SDL_RenderFillRect(renderer, &D13);
                SDL_RenderFillRect(renderer, &D14);
                
                
                SDL_RenderPresent(renderer);
                SDL_Delay(5000);

            }
        // Compute elapsed time since the begin of current frame:
        frame_delay = frame_rate_ms - (SDL_GetTicks() - frame_start);

        // Wait for some time in order to stabilise frame rate to ~20ms:
        if (frame_delay > 0)
        SDL_Delay(frame_delay);

        // Print a warning if the game is too slow with respect to the frame rate:
        if (frame_delay > frame_rate_ms)
        printf("WARNING: frame rate drop: %d ms\n", frame_delay - frame_rate_ms);

        // Check for Quit event:
        
        SDL_PollEvent(&event);
        iter++;

        return 0;
    } while (!(event.type == SDL_QUIT));
    
}





    /*
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    */
    
    

/*
int MainSDLWindow::getRenderer(){

    //SDL_Renderer* renderer;
    return 0;
    
}
*/
MainSDLWindow::MainSDLWindow(){
    window = NULL;
    renderer=NULL;
}

MainSDLWindow::~MainSDLWindow(){

    }


int main(void){
    MainSDLWindow main_window;
    main_window.init();
    main_window.game(20,7);
}