#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "window.hpp"
#include "draw.hpp"

void Draw::draw(){

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 200, 0, 255);
    SDL_RenderFillRect(renderer, &body);
    

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 150, 0, 255);
    SDL_RenderFillRect(renderer, &head);
    
    SDL_RenderPresent(renderer);
    SDL_Delay(20);

}
/*
if(lose){
    
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
    SDL_RenderFillRect(renderer, &head);

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

return EXIT_SUCCESS;
*/