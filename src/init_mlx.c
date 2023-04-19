#include "cub3d.h"

int	close_win(t_mlx *mlx)
{
	free_all(mlx->cube);
	return (0);
}

int	key_hooks(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		close_win(mlx);
	return (0);
}

void	init_mlx(t_cube *cube)
{
	t_mlx	*mlx;
	
	mlx = &cube->mlx;
	mlx->mlx_ptr = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "Cub3D");
	// Add own image functions here.
	mlx_hook(mlx->window, ESCAPE, 0, &close_win, &mlx);
	mlx_key_hook(mlx->window, &key_hooks, &mlx);
	mlx_do_sync(mlx->mlx_ptr); //Improves performance source ChatGPT 
	mlx_loop(mlx->mlx_ptr);
}

// void	my_mlx_pixel_put(t_hold *hold, int x, int y, int color)
// {
// 	char	*dst;

// 	if (x < WIDTH && y < HEIGHT && x > 0 && y > 0)
// 	{
// 		dst = hold->data_addr + (y * hold->size_line + x * (hold->bits_per_pixel / 8));
// 		*(unsigned int *)dst = color;
// 	}
// }