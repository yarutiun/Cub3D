#include "cub3d.h"

unsigned int	my_mlx_pixel_get(t_img *img, int x, int y)
{
	char	*dst;

	dst = img->address + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->address + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	determine_wall_type(t_rc *rc)
{
	if (rc->side == 0)
	{
		if (rc->ray_dir.x <= 0)
			rc->wall_type = SOUTH_WALL;
		else
			rc->wall_type = NORTH_WALL;
	}
	else
	{
		if (rc->ray_dir.y >= 0)
			rc->wall_type = EAST_WALL;
		else
			rc->wall_type = WEST_WALL;
	}
}

void	determine_wall_coordinates(t_rc *rc)
{
	double	wall_hit;

	if (rc->side == 0)
		wall_hit = rc->position.y + rc->perp_wall_dist * rc->ray_dir.y;
	else
		wall_hit = rc->position.x + rc->perp_wall_dist * rc->ray_dir.x;
	wall_hit -= floor(wall_hit);
	rc->texture.x = (int)(wall_hit * (double)(rc->walls[rc->wall_type].width));
	if (rc->side == 0 && rc->ray_dir.x > 0)
		rc->texture.x = rc->walls[rc->wall_type].width - rc->texture.x - 1;
	if (rc->side == 1 && rc->ray_dir.y < 0)
		rc->texture.x = rc->walls[rc->wall_type].width - rc->texture.x - 1;
	rc->texture_step = 1.0 * rc->walls->height / rc->line_height;
	rc->texture_position = (rc->draw_start - PITCH - HEIGHT / 2 + \
							rc->line_height / 2) * rc->texture_step;
}

void	draw_vertical_line(t_rc *rc, int x)
{
	int				y;
	unsigned int	wall_color;
	int				tex_pos;

	determine_wall_type(rc);
	determine_wall_coordinates(rc);
	y = 0;
	while (y < HEIGHT)
	{
		if (y < rc->draw_start)
			my_mlx_pixel_put(&rc->cube->img, x, y, rc->ceiling_color);
		else if (y > rc->draw_end)
			my_mlx_pixel_put(&rc->cube->img, x, y, rc->floor_color);
		else
		{
			tex_pos = (int)rc->texture_position;
			rc->texture.y = tex_pos & (rc->walls[rc->wall_type].height - 1);
			rc->texture_position += rc->texture_step;
			wall_color = my_mlx_pixel_get(rc->walls[rc->wall_type].img, \
											rc->texture.x, rc->texture.y);
			my_mlx_pixel_put(&rc->cube->img, x, y, wall_color);
		}
		y++;
	}
}
