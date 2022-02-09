#include <stdlib.h>
#include <stdio.h>
#include "window.hpp"
#include "food.hpp"

const Uint8 Food::FOOD_RED = 0xCC;

const unsigned int Food::FOOD_WIDTH = 20;


Food::Food(): collide(0,0) {
    m_x = (int) ((Screen::S_WIDTH / FOOD_WIDTH - 2.0) * (1.0 * rand() / RAND_MAX) + 1) * FOOD_WIDTH;
	m_y = (int) ((Screen::S_HEIGHT / FOOD_WIDTH - 4.0) * (1.0 * rand() / RAND_MAX) + 1) * FOOD_WIDTH;
}

void Food::draw(Screen & screen) {
    for (int i = 0; i < FOOD_WIDTH; i++)
		for (int j = 0; j < FOOD_WIDTH; j++)
			screen.setPixel((int) m_x + i, (int) m_y + j, Food::FOOD_RED);
}