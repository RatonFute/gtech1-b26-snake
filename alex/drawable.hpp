#include "SDL2/SDL.h"
#include "window.hpp"

struct Drawable{
    int m_x;
    int m_y;
    Drawable(int x, int y): m_x(x),m_y(y) {}

    virtual void draw(Screen & screen) = 0; 
};
