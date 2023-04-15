#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_cube	*cube;
	t_param	*param;

	cube = malloc(sizeof(t_cube));
	param = malloc(sizeof(t_param));
	cube->param = param;
	parser(argc, argv[1], param);
	free_all(cube);
	return (0);
}
