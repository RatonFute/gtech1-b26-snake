#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv){
    if(SDL_Init(SDL_INIT_VIDEO) != 0){
        fprintf(stdout,"Fail");
        return -1;
    }
    {
        SDL_Window* pWindow = NULL;
        pWindow = SDL_CreateWindow("Test",SDL_WINDOWPOS_UNDEFINED,
                                        SDL_WINDOWPOS_UNDEFINED,
                                        640,
                                        480,
                                        SDL_WINDOW_SHOWN);
        if (pWindow){
            SDL_Delay(3000);
            SDL_DestroyWindow(pWindow);
        }
        else{
            fprintf(stderr,"Fail 2: %s\n",SDL_GetError());
        }
    }
    SDL_Quit();
    return 0;
}