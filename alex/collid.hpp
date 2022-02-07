#include "SDL2/SDL.h"
#include "window.hpp"
#include "drawable.hpp"

#ifndef collid.hpp
#define collid.hpp

namespace SnakeGame {

struct collide: draw {

    collide(int x, int y);
    
    bool collidesWith(collide & other);
};

}

#endif