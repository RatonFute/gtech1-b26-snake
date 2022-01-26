#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "exercice1.hpp"



int MainSDLWindow::init(){
        
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

int MainSDLWindow::game(){
    
    
    SDL_Rect rectangle = {150,150,250,250};
    while (Game)
    {
        SDL_Event events;
        while(SDL_PollEvent(&events))
        {
            switch(events.type)
            {
                case SDL_QUIT:
                Game = false;
                break;
            }
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_RenderFillRect(renderer, &rectangle);
        
        SDL_RenderPresent(renderer);
        SDL_Delay(10);

    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}

/*int MainSDLWindow::getRenderer(){

    //SDL_Renderer* renderer;
    return 0;
    
}

MainSDLWindow::MainSDLWindow(){
        window = NULL;
        renderer=NULL;
}

MainSDLWindow::~MainSDLWindow(){
    //delete window;
    //delete renderer;
    }
*/

    int main(void){
        MainSDLWindow main_window;
        main_window.init();
        main_window.game();
        
        
        
        
    
}