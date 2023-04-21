#include "cub3d.h"

int	x_close(void)
{
	exit(EXIT_SUCCESS);
}

int	key_hooks(int keycode)
{
	if (keycode == 53)
		x_close();
	return (0);
}

void	load_images(t_cube *cube)
{
	int i;
	int j;

	i = 100;
	j = 100;
	cube->img.wall_ptr = mlx_xpm_file_to_image(cube->mlx.mlx_ptr, cube->param.no, &i, &j);
}

void render_map(t_cube *cube)
{
	int		i;
	int		j;
	int		x_cord;
	int		y_cord;

	y_cord = 0;
	i = 0;
	while (i < (HEIGHT / 100))
	{
		x_cord = 0;
		j = 0;
		while (j < (WIDTH / 100))
		{
			mlx_put_image_to_window(cube->mlx.mlx_ptr, \
			cube->mlx.window, cube->img.wall_ptr, x_cord, y_cord);
			++j;
			x_cord += 100;
		}
		y_cord += 100;
		++i;
	}	
}

void	launch_mlx(t_cube *cube)
{
	t_mlx	*mlx;
	t_img	*img;

	mlx = &cube->mlx;
	img = &cube->img;
	mlx->mlx_ptr = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "Cub3D");
	img->img = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
	img->address = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
									&img->line_length, &img->endian);
	// raycasting(cube);
	mlx_hook(mlx->window, ESCAPE, 0, x_close, 0);
	mlx_key_hook(mlx->window, key_hooks, 0);
	mlx_do_sync(mlx->mlx_ptr);
	load_images(cube);
	render_map(cube);
	mlx_loop(mlx->mlx_ptr);
}
