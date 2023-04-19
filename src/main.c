#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_cube	cube;

	init_cube(&cube);
	init_param(&cube);
	parse_input(argc, argv[1], &cube);
	// printf("%s\n\n", cube.param.no); // delete
	// init_mlx(&cube);
	return (0);
}
