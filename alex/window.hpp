#include "SDL2/SDL.h"
#include <string>

#ifndef window.hpp
#define window.hpp

namespace Snakegame{

class Screen {
public:
private:
        SDL_Window * fenetre;
        SDL_Renderer * pRenderer;
        Uint8 * buffer;
        };
};




#endif