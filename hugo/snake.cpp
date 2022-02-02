#include <iostream>
#include "snake.hpp"


Segment Snake::getHead(){
    {return *head;}
}

void Snake::move()
{
    delBack();
    growAtHead();
}

void Snake::turn(int dir)
{

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

void Snake::growBack()
{
    Segment *loop = head;

    while (loop->next != NULL)
    {
        loop = loop->next;
    }

    int xPos = loop->getX();
    int yPos = loop->getY();

    switch (loop->getDir())
    {
    case 0:
        yPos += PAS;
        break;
    case 1:
        yPos -= PAS;
        break;
    case 2:
        xPos -= PAS;
        break;
    case 3:
        xPos += PAS;
        break;
    default:
        break;
    }

    Segment *newSegment  = new Segment(xPos, yPos, loop->getDir());

    newSegment->setY(yPos);
    newSegment->setDir(head->getDir());
    newSegment->next = head;
    loop->next = newSegment;



}


void Snake::delBack()
{
    Segment *loop = head;
    Segment *last = NULL;
    if(head->next == NULL)
    {
        head = NULL;
    }
    else
    {
        while(loop->next->next != NULL)
        {
            loop = loop->next;
        }
        last = loop->next;
        loop->next = NULL;
        delete last;
    }


}
