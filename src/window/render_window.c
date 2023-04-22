#include "cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->address + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	add_pixel(t_cube *cube, int x, int y)
{
	int color = 0x000066FF;

	color = raycasting(cube);
	my_mlx_pixel_put(&cube->img, x, y, color);
}

void	draw_vertical_lines(t_cube *cube)
{
	int	pixel_x;
	int	pixel_y;

	pixel_x = cube->img.pixel_x;
	pixel_y = cube->img.pixel_y;
	pixel_x = 0;
	while (pixel_x < WIDTH)
	{
		pixel_y = 0;
		while (pixel_y < HEIGHT)
		{
			add_pixel(cube, pixel_x, pixel_y);
			pixel_y++;
		}
		pixel_x++;
	}
}

void	render_window(t_cube *cube)
{
	mlx_clear_window(cube->mlx.mlx_ptr, cube->mlx.window);
	draw_vertical_lines(cube); //From left to right, form bottom to top
	mlx_put_image_to_window(cube->mlx.mlx_ptr, cube->mlx.window, \
							cube->img.img, 0, 0);
}
