#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_cube	cube;

	init_cube(&cube);
	init_param(&cube);
	parse_input(argc, argv[1], &cube.param);
	free_all(&cube);
	return (0);
}
