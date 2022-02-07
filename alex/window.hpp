#include "SDL2/SDL.h"
#include <string>




class Screen {
public :
        enum Action { QUIT, MOVE_UP, MOVE_DOWN, MOVE_LEFT, MOVE_RIGHT, PAUSE };
private:
        SDL_Window *fenetre;
        SDL_Renderer *pRenderer;
public:
        Screen();
        ~Screen();
        bool init();
        int processEvents();
        void update(int score, bool isGameOver);
};