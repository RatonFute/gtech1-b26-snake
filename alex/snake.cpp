#include <iostream>
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "window.hpp"
#include "snake.hpp"

const Uint8 Snake::SNAKE_GREEN = 0xFF;
const int Snake::INITIAL_SPEED = 1;
cint Snake::INITIAL_DIRECTION = Snake::Direction::RIGHT;
cint Snake::N_SECTS = 1;

Snake::Snake(): m_speed(Snake::INITIAL_SPEED), m_direction(INITIAL_DIRECTION){
	Section * newSection = nullptr;
	for (int i = 0; i < S_N_SECTS; i++) {
		newSection = new Section(Screen::S_WIDTH/2 - i*Section::S_SECTION_WIDTH,
			3*Section::S_SECTION_WIDTH);
		m_sections.push_back(newSection);
	}