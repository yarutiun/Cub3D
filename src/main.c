#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_cube	cube;

	init_structs(&cube);
	parse_input(argc, argv[1], &cube);
	launch_mlx(&cube);
	return (0);
}
