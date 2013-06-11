#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "base.h"

int	managerinput(SDL_Surface* ecran, terrain_map* terrainbomber, characters* spritetest)
{
	SDL_Delay(10);
	SDL_Event	event;
	SDL_EnableKeyRepeat(1000,1000);
	SDL_PollEvent(&event);
	switch(event.type)
	{
		case SDL_KEYDOWN:
		 switch(event.key.keysym.sym)
		{
			case SDLK_RIGHT:
			spritetest->run(ecran,terrainbomber,1);
			break;
			case SDLK_LEFT:
			spritetest->run(ecran,terrainbomber,2);
			break;
			case SDLK_UP:
			spritetest->run(ecran,terrainbomber,3);
			break;
			case SDLK_DOWN:
			spritetest->run(ecran,terrainbomber,4);
		}	
			break;
		case SDL_QUIT:
			return 0;
	}

	return 1;
}


int main(int argc, char *argv[])
{
	mysdl sdlbomber;
	terrain_map terrainbomber(130);
	menu	menuG;
	sdlbomber.init_sdl();
	menuG.show_menuG(sdlbomber.ecran);
	terrainbomber.generate_all();
	terrainbomber.show_all(sdlbomber.ecran);


	//SPRITE START

	characters	spritetest(sdlbomber.ecran);
	while(managerinput(sdlbomber.ecran,&terrainbomber,&spritetest))
	{
		
	}
	//SPRITE FIN

	//checkmap();
	SDL_Flip(sdlbomber.ecran);
	sdlbomber.pause();
	SDL_Quit();

}
