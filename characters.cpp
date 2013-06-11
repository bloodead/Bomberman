#include "base.h"


characters::characters(SDL_Surface *ecran)
{
	frame = 0;
	offsetx = 24;
	offsety = 32;
	image = IMG_Load("./sprite.png");
	SDL_SetColorKey(image, SDL_SRCCOLORKEY,SDL_MapRGB(image->format, 40, 152, 0));
	source.x = 0;
	source.y = 0;
	dest.x = 24;
	dest.y = 32;
	dest.w = 24;
	dest.h = 32;
	SDL_BlitSurface(image, &dest, ecran, &source);
}

void	characters::run(SDL_Surface* ecran, terrain_map* terrainbomber, int pos)
{
	switch (pos)
	{
		case 1:
			dest.y = 32;
			source.x += 1;
		break;
		case 2:
			dest.y = 96;
			source.x -= 1;
		break;
		case 3:
			dest.y = 0;
			source.y -= 1;
		break;
		case 4:
			dest.y = 64;
			source.y += 1;
		break;
	}


	frame += 1;
	if (frame == 7)
	{
		dest.x += offsetx;
		frame = 0;
	}
	if (dest.x >= offsetx * 3)
		dest.x = 0;
	SDL_FillRect(ecran,NULL, SDL_MapRGB(image->format, 0, 0, 0));
	terrainbomber->show_all(ecran);
	SDL_BlitSurface(image, &dest, ecran, &source);
	SDL_Flip(ecran);

}
