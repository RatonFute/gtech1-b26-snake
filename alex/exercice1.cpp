#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "exercice1.hpp"

SDL_Window* fenetre;
SDL_Renderer* renderer;

if(SDL_VideoInit(NULL) < 0)
{
    printf("Error %s",SDL_GetError());
    return EXIT_FAILURE;
}
fenetre = SDL_CreateWindowAndRenderer(600 , 600 , SDL_WINDOW_RESIZABLE , &fenetre, &renderer);
if(fenetre == NULL) // Gestion des erreurs
{
    printf("Erreur lors de la creation d'une fenetre : %s",SDL_GetError());
    return EXIT_FAILURE;
}

renderer = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC); // Création du renderer

SDL_Delay(10000);

// Destruction du renderer et de la fenêtre :
SDL_DestroyRenderer(renderer); 
SDL_DestroyWindow(fenetre);
SDL_Quit(); // On quitte la SDL


/*int main (int argc, char** argv)
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
    
    SDL_Delay(10000);
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
    return 0;
}*/