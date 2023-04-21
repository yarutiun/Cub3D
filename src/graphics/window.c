#include "cub3d.h"

int	x_close(t_cube *cube)
{
	// (void)cube;
	free_all(cube);
	exit(EXIT_SUCCESS);
}

int	key_hooks(int keycode, t_cube *cube)
{
	if (keycode == 53)
		x_close(cube);
	return (0);
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
	mlx_hook(mlx->window, ESCAPE, 0, &x_close, &cube);
	mlx_key_hook(mlx->window, &key_hooks, &cube);
	mlx_do_sync(mlx->mlx_ptr);
	mlx_loop(mlx->mlx_ptr);
}
