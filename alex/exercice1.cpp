#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char** argv)
{
    SDL_Window* fenetre;
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        fprintf(stdout,"Fail");
        return -1;
    }
    fenetre = SDL_CreateWindow("Test",SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        640,
        480,
        SDL_WINDOW_RESIZABLE);
    if (fenetre == NULL){
        printf("Erreur lors de la creation d'une fenetre : %s", SDL_GetError());
        return EXIT_FAILURE;
    }
    
    SDL_Delay(3000);
    SDL_DestroyWindow(pWindow);
    SDL_Quit();
    return 0;
}