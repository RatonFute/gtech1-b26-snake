#include "SDL2/SDL.h"
#include "window.hpp"
#include "drawable.hpp"


struct collide: Drawable{

    collide(int x, int y);
    
    bool collidesWith(collide & other);
};