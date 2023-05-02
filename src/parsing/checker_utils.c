#include "cub3d.h"

void	check_if_3_nums(char **rgb_c, char **rgb_f, t_param *param)
{
	if (array_size(rgb_c) != 3 || array_size(rgb_f) != 3)
	{
		free_double_str_ptr(rgb_c);
		free_double_str_ptr(rgb_f);
		rgb_error(param->cube);
	}
}

void	free_for_rgb(char **rgb_c, char **rgb_f, t_param *param)
{
	free_double_str_ptr(rgb_c);
	free_double_str_ptr(rgb_f);
	rgb_error(param->cube);
}

void	check_open_top(char **map, t_cube *cube)
{
	int	j;

	j = 0;
	while (map[0][j])
	{
		if (map[0][j] == '0')
			map_row_error(cube);
		j++;
	}
	j = 0;
	while (map[array_size(map) - 1][j])
	{
		if (map[array_size(map) - 1][j] == '0')
			map_row_error(cube);
		j++;
	}
}
