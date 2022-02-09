#include "collid.hpp"


collide::collide(int x, int y): Drawable(x,y){}

bool collide::collidesWith(collide & other) {
    return m_x == other.m_x && m_y == other.m_y;
};