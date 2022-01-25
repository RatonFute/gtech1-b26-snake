#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

SDL_Window* fenetre;
SDL_Renderer* renderer;

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
    renderer = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL){
        printf("Erreur lors de la creation du renderer : %s", SDL_GetError());
        return EXIT_FAILURE;
    }
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderDrawLine(renderer,0,90,45,120);
    SDL_Delay(5000);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
    return 0;
}