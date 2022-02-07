#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "window.hpp"


Screen::Screen(){}

Screen::~Screen(){}



bool Screen::init(){
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "Marche pas" << std::endl;
        return false;
    }

    fenetre = SDL_CreateWindow("Snake",SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED, 1280, 720, 0);

    if (!fenetre) {
        SDL_Log("Fenêtre Pas La");
        SDL_Log("%s", SDL_GetError());
        SDL_Quit();
        return false;
    }

    pRenderer = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_PRESENTVSYNC);

    if(!pRenderer) {
        SDL_Log("Renderer Pas La");
        SDL_Log("%s", SDL_GetError());
        SDL_DestroyRenderer(pRenderer);
        SDL_DestroyWindow(fenetre);
        SDL_Quit();
        return false;

    }

    return true;

}

int Screen::processEvents() {
    SDL_Event event;
    int action = -1;
    while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				action = Action::QUIT;
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
					case SDLK_LEFT:
						action = Action::MOVE_LEFT;
						break;
					case SDLK_RIGHT:
						action = Action::MOVE_RIGHT;
						break;
					case SDLK_DOWN:
						action = Action::MOVE_DOWN;
						break;
					case SDLK_UP:
						action = Action::MOVE_UP;
						break;
					case SDLK_RETURN:
						action = Action::PAUSE;
						break;
				}
				break;
		}
	}

	return action;
}
void Screen::update(int score, bool isGameOver) {
	SDL_RenderClear(pRenderer);
	/*if (!isGameOver)
		drawText(score);*/
	SDL_RenderPresent(pRenderer);
}

