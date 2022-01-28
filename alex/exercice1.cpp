#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>


int main (int argc, char** argv)
{
    SDL_Window* fenetre;
    SDL_Renderer* pRenderer;
    if(SDL_VideoInit(NULL) < 0)
    {
        printf("Fail :%s",SDL_GetError());
        return EXIT_FAILURE;
    }
    fenetre = SDL_CreateWindow("Snake",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, 0);
    if (fenetre == NULL)
    {
        printf("Erreur lors de la creation d'une fenetre : %s", SDL_GetError());
        return EXIT_FAILURE;
    }
    pRenderer = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    if (pRenderer == NULL)
    {
        printf("Erreur lors de la creation du renderer : %s", SDL_GetError());
        return EXIT_FAILURE;
    }
    bool Game{true};
    Uint32 frame_rate = 160;
    SDL_Rect rectangle;
     rectangle.x = 350;
     rectangle.y = 350;
     rectangle.h = 50;
     rectangle.w = 50;

    while (Game == true)
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
            const Uint8 *keystates = SDL_GetKeyboardState(NULL);
            if (keystates[SDL_SCANCODE_UP]) 
            {
                rectangle.y -= 5;
                SDL_Delay(10);
                break;
            }
            if (keystates[SDL_SCANCODE_DOWN]) 
            {
                rectangle.y += 5;
                SDL_Delay(10);
                break;
            }
            if (keystates[SDL_SCANCODE_LEFT]) 
            {
                rectangle.x -= 5;
                SDL_Delay(10);
                break;
            }
            if (keystates[SDL_SCANCODE_RIGHT]) 
            {
                rectangle.x += 5;
                SDL_Delay(10);
                break;
            }
        }
        SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 0);
        SDL_RenderClear(pRenderer);

        SDL_SetRenderDrawColor(pRenderer, 0, 255, 0, 255);
        SDL_RenderFillRect(pRenderer, &rectangle);
        SDL_RenderPresent(pRenderer);
        SDL_Delay(100);
    }
    SDL_DestroyRenderer(pRenderer);
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
    return EXIT_SUCCESS;
}