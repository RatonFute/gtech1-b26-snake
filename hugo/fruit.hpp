#pragma once
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

class Fruit{
    public:
        Fruit();
        ~Fruit(); 
        void spawn(int windowSize,int size);
        void draw(SDL_Renderer* renderer,int size);
        void destroy();
    private: 
        int x;
        int y;
};
