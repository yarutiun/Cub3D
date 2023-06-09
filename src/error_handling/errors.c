#include "cub3d.h"

void	error_exit(char *message, t_cube *cube)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(message, 2);
	free_all(cube);
	exit(1);
}

void	rgb_error(t_cube *cube)
{
	error_exit("Invalid RGB arguments\n", cube);
}

void	extension_error(t_cube *cube)
{
	error_exit("Invalid file extension\n", cube);
}

void	init_elements_error(t_cube *cube)
{
	error_exit("Invalid elements on input file\n", cube);
}

void	argc_error(t_cube *cube)
{
	error_exit("Invalid number of arguments\n", cube);
}
