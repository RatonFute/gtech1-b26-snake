#include "window.hpp"
#include "collid.hpp"
#include <SDL2/SDL.h>
#include <stdio.h>

struct Food: collide {
    static const Uint8 FOOD_RED;
    static const unsigned int FOOD_WIDTH;
    Food();
    void draw(Screen & screen);
};