#include "cub3d.h"

void	player_error_if(t_cube *cube, int flag)
{
	if (flag == 0)
		player_error(cube, "No players on the map\n");
	else if (flag > 1)
		player_error(cube, "Too many players on the map\n");
}