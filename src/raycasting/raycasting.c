#include "cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->address + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_xy	rotate_direction(t_ray *ray, int i)
{
	double	angle;

	angle = (-1 * FOV/2) + (ray->ray_angle_diff * i);
	ray->tmp_direction.x = (ray->direction.x * cos(angle * M_PI/180)) - (ray->direction.y * sin(angle * M_PI/180));
	ray->tmp_direction.y = (ray->direction.x * sin(angle * M_PI/180)) + (ray->direction.y * cos(angle * M_PI/180));
}

double	h_raycast(t_ray *ray)
{

}

double	single_ray(t_ray *ray)
{
	double	horizontal_rc;
	double	vertical_rc;

	horizontal_rc = h_raycast(ray);
	vertical_rc = v_raycast(ray);
	if (horizontal_rc < vertical_rc)
	{
		if (ray->tmp_direction.y < 0)
			ray->current_wall = NORTH_WALL;
		else
			ray->current_wall = SOUTH_WALL;
		ray->intersection = ray->h_intersection;
		return (horizontal_rc);
	}
	else
	{
		if (ray->tmp_direction.x < 0)
			ray->current_wall = WEST_WALL;
		else
			ray->current_wall = EAST_WALL;
		ray->intersection = ray->h_intersection;
		return (vertical_rc);
	}
}

void	raycasting(t_cube *cube)
{
	t_ray	*ray;
	int		i;

	ray = &cube->ray;
	while (i < RAY_COUNT)
	{
		rotate_direction(ray, i);
		ray->distance = single_ray(ray);
		i++;
	}
}