#include "cub3d.h"

void	render_window(t_cube *cube)
{
	mlx_clear_window(cube->mlx.mlx_ptr, cube->mlx.window);
	raycasting(cube);
	mlx_put_image_to_window(cube->mlx.mlx_ptr, cube->mlx.window, \
							cube->img.img, 0, 0);
}

void	launch_window(t_cube *cube)
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
	init_starting_values(cube);
	load_textures(cube);
	render_window(cube);
	mlx_hook(mlx->window, CLOSE_WINDOW, 0, x_close, 0);
	mlx_hook(mlx->window, 2, 0, key_hooks, &cube->rc);
	mlx_do_sync(mlx->mlx_ptr);
	mlx_loop(mlx->mlx_ptr);
}
