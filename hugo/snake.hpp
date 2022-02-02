#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "segment.hpp"
#ifndef SNAKE_HPP
#define SNAKE_HPP



class Snake{
    public:
        Segment getHead();
        void turn(int dir);
        void move();
        void spawn();

    private:
        int dir; 
        Segment* head = NULL;
    
};

 #endif