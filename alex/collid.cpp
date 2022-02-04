#include "collid.hpp"

namespace SnakeGame {

void collid::collid(int x, int y): Drawable(x,y){}

bool collid::collidesWith(collid & other) {
    return m_x == other.m_x && m_y == other.m_y;
};


}