#include "cub3d.h"

void	init_param(t_cube *cube)
{
	t_param	*param;

	param = cube->param;
	param->input_str = NULL;
	param->splitted_input = NULL;
	param->no = NULL;
	param->so = NULL;
	param->we = NULL;
	param->ea = NULL;
	param->f = NULL;
	param->c = NULL;
	param->f_rgb = malloc(sizeof(int) * 3);
	param->c_rgb = malloc(sizeof(int) * 3);
	param->map = NULL;
}

int	x_close(void)
{
	exit(EXIT_SUCCESS);
}

void	init_mlx(t_cube *cube)
{
	t_mlx	*mlx;

	mlx = cube->mlx;
	mlx->mlx_ptr = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx_ptr, 1920, 1080, "Cub3D");
	mlx_hook(mlx->window, 17, 0, x_close, 0);
	mlx_loop(mlx->mlx_ptr);
	// mlx_destroy_window(mlx->mlx_ptr, mlx->window);
}

void	init_cube(t_cube *cube)
{
	cube->param->cube = cube;
}
