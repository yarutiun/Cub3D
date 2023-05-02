#include "cub3d.h"

void	error_double_n(t_cube *cube)
{
	error_exit("Empty line in map\n", cube);
}

void	map_row_error(t_cube *cube)
{
	error_exit("Open map\n", cube);
}

void	invalid_spaces_error(t_cube *cube)
{
	error_exit("Invalid space positon\n", cube);
}

void	forbidden_chars_error(t_cube *cube)
{
	error_exit("Invalid characters\n", cube);
}

void	out_of_bounds_error(t_cube *cube)
{
	error_exit("Player out of bounds. Get gnomed!\n", cube);
}
