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

    fenetre = SDL_CreateWindow("Snake",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, 0);
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

    int x = 350;
    int y = 350;

    int incrX = 0;
    int incrY = 0;

    int tps_prec;
    int tps_act;

    SDL_Rect rectangle;
     rectangle.x = x;
     rectangle.y = y;
     rectangle.h = 20;
     rectangle.w = 20;

    while (Game == true)
    {

        SDL_Event events;
        tps_prec = SDL_GetTicks();
        while(SDL_PollEvent(&events))
        {
            switch(events.type)
            {
                case SDL_QUIT:
                Game = false;
                break;
            }
        }

        const Uint8 *keystates = SDL_GetKeyboardState(NULL);
        if (keystates[SDL_SCANCODE_UP]) 
        {
            incrX=0;
            incrY=-rectangle.h;
        }
        else if (keystates[SDL_SCANCODE_DOWN])
        {
            incrX=0;
            incrY=rectangle.h;
        }
        else if (keystates[SDL_SCANCODE_LEFT])
        {
            incrX=-rectangle.h;
            incrY=0;
        }
        else if (keystates[SDL_SCANCODE_RIGHT])
        {
            incrX=rectangle.h;
            incrY=0;
        }
        tps_act = SDL_GetTicks();
        if (tps_act - tps_prec < 60)
        {
            SDL_Delay(60 - (tps_act - tps_prec));
        }

        SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 0);
        SDL_RenderClear(pRenderer);

        SDL_SetRenderDrawColor(pRenderer, 0, 255, 0, 255);
        SDL_RenderFillRect(pRenderer, &rectangle);

        SDL_RenderPresent(pRenderer);

        rectangle.x=rectangle.x + incrX;
        rectangle.y=rectangle.y + incrY;
    }        
    SDL_DestroyRenderer(pRenderer);
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
    return EXIT_SUCCESS;
}