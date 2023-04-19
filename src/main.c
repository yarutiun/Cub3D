#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_cube	cube;

	init_cube(&cube);
	init_param(&cube);
	parse_input(argc, argv[1], &cube);
	printf("%s", cube.param->no);
	// init_mlx(&cube);
	free_all(&cube);
	return (0);
}
