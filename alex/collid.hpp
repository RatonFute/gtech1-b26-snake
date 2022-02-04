#include "SDL2/SDL.h"
#include "window.hpp"
#include "draw.hpp"

#ifndef collid.hpp
#define collid.hpp

namespace SnakeGame {

struct collid: draw {

    collid(int x, int y)
    
    bool collidesWith(collid & other);
};

}

#endif