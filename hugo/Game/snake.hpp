#pragma once
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "segment.hpp"


class Snake{
    public:
        Snake(int size,int dir);
        ~Snake();
        void turn(int dir);
        void spawn(int x,int y,int dir);
        void addsegment();
        void move();
        void draw(SDL_Renderer* renderer);
    private:
        Segment* head=NULL;
        SDL_Renderer* renderer;
        SDL_Window* window;
};
