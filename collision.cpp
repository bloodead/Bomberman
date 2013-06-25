#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "base.h"



int	detect_colli(terrain_map *terrain, int	pos, int y , int x)
{
	int	id;

	id = 0;

	while (id != terrain->size_map)
	{
	switch (pos)
	{
		case 1:
			if ((x >= terrain->id_case[id].position.x - 25) && x <= (terrain->id_case[id].position.x + 25) && terrain->id_case[id].type == 1 && ((y >= terrain->id_case[id].position.y - 25) &&  y <= (terrain->id_case[id].position.y + 25)))
			return 1;
		break;
		case 2:
			if ((x >= terrain->id_case[id].position.x - 25) && x <= (terrain->id_case[id].position.x + 25) && terrain->id_case[id].type == 1 && ((y >= terrain->id_case[id].position.y - 25) &&  y <= (terrain->id_case[id].position.y + 25)))
			return 1;
		break;
		case 3:
			if ((x >= terrain->id_case[id].position.x - 25) && x <= (terrain->id_case[id].position.x + 25) && terrain->id_case[id].type == 1 && ((y >= terrain->id_case[id].position.y - 25) &&  y <= (terrain->id_case[id].position.y + 25)))
			return 1;
		break;

		case 4:
			if ((x >= terrain->id_case[id].position.x - 25) && x <= (terrain->id_case[id].position.x + 25) && terrain->id_case[id].type == 1 && ((y >= terrain->id_case[id].position.y - 25) &&  y <= (terrain->id_case[id].position.y + 25)))
			return 0;
		break;
	}
	id++;
	}
	return 0;
}
