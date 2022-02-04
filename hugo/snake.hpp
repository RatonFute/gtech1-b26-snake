#include "segment.hpp"
#ifndef SNAKE_HPP
#define SNAKE_HPP



class Snake{
    public:
        Snake(int size,int dir);
        void turn(int dir);
        int spawn(int x,int y,int dir);
        void addsegment();  
        void move();
        void draw();
    private:
        Segment* head=NULL;
        SDL_Renderer* renderer;
        SDL_Window* window;
     
};

 #endif