#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "segment.hpp"

typedef const unsigned int cint;

struct Snake {
  static const Uint8 SNAKE_GREEN;
  static const int INITIAL_SPEED;
  static cint INITIAL_DIRECTION;
  static cint N_SECTS;

  enum Direction { UP, DOWN, LEFT, RIGHT };

  int m_speed;
  int m_direction;

  Snake();
  ~Snake();

  void draw(Screen & screen);
  void updateDirection(int direction);
  bool move();
  bool collidesWith(collide & object);
  void addSection();
  
};