#include "base.h"
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>


	menu::menu()
{
	TTF_Init();

}

void	menu::changemenucolorG(int	color,SDL_Surface *ecran)
{
	if (color == 1)
	textmenuG.color = {255,0,0};
	
	if (color == 0)
	textmenuG.color = {255,255,255};
	textmenuG.menuG = TTF_RenderText_Blended(textmenuG.police,"New Games",textmenuG.color);
	SDL_BlitSurface(textmenuG.menuG,NULL,ecran,&textmenuG.position);
	SDL_Flip(ecran);

}

void	menu::show_menuG(SDL_Surface	*ecran)
{
	textmenuG.color = {255,255,255};
	textmenuG.police = TTF_OpenFont("HungerGames.ttf",35);
	textmenuG.menuG = TTF_RenderText_Blended(textmenuG.police,"New Games",textmenuG.color);
	textmenuG.position.x = 200;
	textmenuG.position.y = 220;
	SDL_BlitSurface(textmenuG.menuG,NULL,ecran,&textmenuG.position);
	SDL_Flip(ecran);
	waitSelectNG(ecran);

}

void	menu::waitSelectNG(SDL_Surface *ecran)
{
	int	focus;
	SDL_Event event;

	focus = 0;
	while (focus != 1)
	{
		SDL_WaitEvent(&event);
		SDL_GetMouseState(&mousemenu.x, &mousemenu.y);
		if (mousemenu.y >= 220 && mousemenu.y <= 255)
			changemenucolorG(1,ecran);
		else
			changemenucolorG(0,ecran);
			//focus = 1;
		switch(event.type)
		{
			case SDL_MOUSEMOTION:
			printf("x : %i  y: %i",mousemenu.x,mousemenu.y);
			break;
			case SDL_MOUSEBUTTONDOWN:
			if (mousemenu.y >= 220 && mousemenu.y <= 255)
				focus =1;
		}
	}

}
