#include "cub3d.h"

void	init_param(t_cube *cube)
{
	t_param	*param;

	param = &cube->param;
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

void	init_mlx(t_cube *cube)
{
	t_mlx	*mlx;

	mlx = &cube->mlx;
	mlx->mlx_ptr = NULL;
	mlx->window = NULL;
}

void	init_img(t_cube *cube)
{
	t_img	*img;

	img = &cube->img;
	img->img = NULL;
	img->address = NULL;
	img->bits_per_pixel = 0;
	img->line_length = 0;
	img->endian = 0;
}

void	init_structs(t_cube *cube)
{
	cube->param.cube = cube;
	init_param(cube);
	cube->mlx.cube = cube;
	init_mlx(cube);
	cube->img.cube = cube;
	init_img(cube);
}