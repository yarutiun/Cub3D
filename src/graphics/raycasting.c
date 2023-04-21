#include "cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < WIDTH && y < HEIGHT && x > 0 && y > 0)
	{
		dst = img->address + (y * img->line_length + x * (img->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	raycasting(t_cube *cube)
{
	mlx_clear_window(cube->mlx.mlx_ptr, cube->mlx.window);
	//draw_vertical_lines(cube); //From left to right, form bottom to top
	mlx_put_image_to_window(cube->mlx.mlx_ptr, cube->mlx.window, \
							cube->img.img, 0, 0);
}
