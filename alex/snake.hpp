#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef snake.hpp
#define snake.hpp

class Snake {
public:
  void Move(int dir);
  void Eat();
  void Print();
private:
};

#endif