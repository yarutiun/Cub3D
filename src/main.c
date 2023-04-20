#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_cube	cube;

	init_structs(&cube);
	parse_input(argc, argv[1], &cube);
	mlx_loop(&cube);
	return (0);
}
