#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "fruit.hpp"


Fruit::Fruit(){}
Fruit::~Fruit(){}

void Fruit::spawn(int windowSize,int size){
    x = rand() % windowSize;
    y = rand() % windowSize;
}

void Fruit::draw(SDL_Renderer* renderer,int size){
    SDL_SetRenderDrawColor(renderer, 100, 20, 100, 255);
    SDL_Rect fruit = {x,y,size,size};

    SDL_RenderFillRect(renderer, &fruit);
    SDL_RenderDrawRect(renderer, &fruit);
}

void Fruit::destroy(){}