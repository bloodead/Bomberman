#include "base.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>

terrain_map::terrain_map(int sizeM)
{
	char path[] = "./herv.jpg";
	char path1[] = "./rock.jpg";
	id_case = new case_map[sizeM];
	size_map = sizeM;
	herb_case = IMG_Load(path);
	rock_case = IMG_Load(path1);
	printf("vien de cree toute les case demander \n");
}


void	terrain_map::generate_all()
{
	int	id;
	char	buff;
	int	fd;

	fd = open("./src.txt",0);
	id = 0;

	while (id != size_map)
	{
		checkfile(fd,&buff);
		if(buff == '+')
			id_case[id].type = 0;
		else
			id_case[id].type = 1;
		id_case[id].id = id;
		id = id + 1;
	}
	printf("tout les donne entrer dans id\n");
}

void	terrain_map::show_all(SDL_Surface *ecran)
{
	int	id;
	int	x;
	int	y;

	id = 0;
	x = 0;
	y = 0;
	while (id != size_map)
	{
		id_case[id].position.y = y;
		id_case[id].position.x = x;
		if (id_case[id].type == 0)
			id_case[id].case_rect = herb_case;
		else
			id_case[id].case_rect = rock_case;
		SDL_BlitSurface(id_case[id].case_rect,NULL,ecran,&id_case[id].position);
		id = id + 1;
		x = x + 50;
		printf("%i \n",x);
		if (x == 650)
		{
		printf("BUG\n");
			y = y + 50;
			x = 0;
		}

	}
	printf("CHECK FINI \n");
}
