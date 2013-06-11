#include "base.h"


void	mysdl::init_sdl()
{

	SDL_Init(SDL_INIT_VIDEO);
	ecran = SDL_SetVideoMode(650, 500, 32, SDL_HWSURFACE);
	SDL_WM_SetCaption("Bomberman Game", NULL);
}


void mysdl::pause()
{
    int continuer = 1;
    SDL_Event event;
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}
