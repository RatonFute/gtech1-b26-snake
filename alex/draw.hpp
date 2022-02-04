#include "SDL2/SDL.h"
#include "window.hpp"

#ifndef draw.hpp
#define draw.hpp

namespace SnakeGame{

struct draw{
    int m_x;
    int m_y;
    draw(int x, int y): m_x(x),m_y(y) {}

    virtual void draw(Screen & screen) = 0; 
};

}

#endif