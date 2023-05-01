#include "cub3d.h"

void    player_error(t_cube *cube, char *msg)
{
    error_exit(msg, cube);
}

void    file_error(t_cube *cube)
{
    error_exit("Texture file not found\n", cube);
}

void    texture_not_loaded_error(t_cube *cube)
{
    error_exit("Could not load texture file\n", cube);
}
