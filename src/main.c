#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_cube	cube;

	init_cube(&cube);
	init_param(&cube);
	parse_input(argc, argv[1], &cube);
	init_mlx(&cube);
	printf("%s", cube.param->no);
	free_all(&cube);
	return (0);
}
