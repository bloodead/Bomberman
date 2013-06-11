#ifndef _BASE_H_
#define _BASE_H_
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>


int	checkfile(int fd,char* buff);
void	checkmap();


class mysdl
{

	public:
		SDL_Surface	*ecran;
		void init_sdl();
		void pause();
	//	void clearScreen();

};

class case_map
{
	public:
	SDL_Surface	*case_rect;
	SDL_Rect	position;
	int	id;

};

class terrain_map
{
	SDL_Surface	*herb_case;
	case_map	*id_case;
	int	size_map;
	public:
	terrain_map(int sizeM);
	void generate_all();
	void show_all(SDL_Surface *ecran);

};

class	textgame
{
	public:
	SDL_Surface	*menuG;
	TTF_Font	*police;
	SDL_Color	color;
	SDL_Rect	position;
};

class	mousepos
{
	public:
	int	x;
	int	y;
};

class	menu
{
	int	numb_level;
	textgame	textmenuG;
	public:
	mousepos	mousemenu;
		menu();
		void	show_menuG(SDL_Surface *ecran);
		void	waitSelectNG(SDL_Surface *ecran);
		void	changemenucolorG(int	color,SDL_Surface *ecran);

};

class	characters
{
	SDL_Surface *image;
	SDL_Rect source;
	SDL_Rect dest;
	int	offsetx;
	int	offsety;
	int	frame;
	public:
		characters(SDL_Surface *ecran);
	void	run(SDL_Surface *ecran, terrain_map* terrainbomber,int	pos);


};

#endif
