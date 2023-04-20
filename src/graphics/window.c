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

void	loop_mlx(t_cube *cube)
{
	t_mlx	*mlx;

	mlx = &cube->mlx;
	mlx->mlx_ptr = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "Cub3D");
	mlx_hook(mlx->window, ESCAPE, 0, x_close, 0);
	mlx_key_hook(mlx->window, key_hooks, 0);
	mlx_do_sync(mlx->mlx_ptr); //Improves performance source ChatGPT
	mlx_loop(mlx->mlx_ptr);
}
