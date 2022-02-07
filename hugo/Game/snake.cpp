#include <iostream>
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "snake.hpp"

#define STEP 10
#define SIZE 20

Snake::Snake(int size,int dir){}
Snake::~Snake(){}

//initiate the snake
void Snake::spawn(int x,int y,int dir){
    
    int posX=x;
    int posY=y;

    Segment *newSegment = new Segment(x,y,2);
    
    newSegment->setX(posX);
    newSegment->setY(posY);
    newSegment->setDir(dir);
    newSegment->end = head;
    head = newSegment;
    
}   

void Snake::turn(int dir){
    switch (dir)
    {
    case 0:
        if (head->getDir() != 1)
            head->setDir(dir);
        break;
    case 1:
        if (head->getDir() != 0)
            head->setDir(dir);
        break;
    case 2:
        if (head->getDir() != 3)
            head->setDir(dir);
        break;
    case 3:
        if (head->getDir() != 2)
            head->setDir(dir);
        break;
    default:
        break;
    }
}

void Snake::addsegment(){

    Segment *loop = head;

    while(loop->end != NULL){
        loop=loop->end;
    }
    
    int posX=loop->getX();
    int posY=loop->getY();
    switch (loop->getDir())
    {
    case 0:
        posY += STEP;
        break;
    case 1:
        posY -= STEP;
        break;
    case 2:
        posX -= STEP;
        break;
    case 3:
        posX += STEP;
        break;
    default:
        break;
    }

    Segment *newSegment = new Segment(posX,posY,loop->getDir());
    newSegment->setX(posX);
    newSegment->setY(posY);
    newSegment->setDir(head->getDir());
    
}

void Snake::move(){

   int posY=head->getY();
   int posX=head->getX();
 
    switch (head->getDir())
    {
    case 0:
        posY -= STEP;
        break;
    case 1:
        posY += STEP;
        break;
    case 2:
        posX += STEP;
        break;
    case 3:
        posX -= STEP;
        break;
    default:
        break;
    }


    Segment *newSegment = new Segment(posX,posY,head->getDir());
    newSegment->setX(posX);
    newSegment->setY(posY);
    newSegment->setDir(head->getDir());
    newSegment->end = head;
    head = newSegment;

    

    Segment *loop = head;
    Segment *last = NULL;
    if(head->end == NULL)
    {
        head = NULL;
    }
    else
    {
        while(loop->end->end != NULL)
        {
            loop = loop->end;
        }
        last = loop->end;
        loop->end = NULL;
        delete last;
    }


}

void Snake::draw(){

    SDL_Rect Heada;
    Heada.x=head->getX();
    Heada.y=head->getY();
    Heada.w=SIZE;
    Heada.h=SIZE;
     
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 150, 0, 255);
    SDL_RenderFillRect(renderer, &Heada);
/*

    SDL_Rect Body;
    Body.x=

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 200, 0, 255);
    SDL_RenderFillRect(renderer, &body);
    
*/
    
    SDL_RenderPresent(renderer);
    SDL_Delay(20);
}