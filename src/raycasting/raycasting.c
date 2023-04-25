#include "cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->address + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

unsigned int	my_mlx_pixel_get(t_img *img, int x, int y)
{
	char	*dst;

	dst = img->address + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	rotate_direction(t_ray *ray, int i)
{
	double	angle;

	angle = (-1 * FOV / 2) + ((FOV / RAY_COUNT) * i);
	ray->tmp_direction.x = (ray->direction.x * cos(angle * M_PI/180)) - (ray->direction.y * sin(angle * M_PI/180));
	ray->tmp_direction.y = (ray->direction.x * sin(angle * M_PI/180)) + (ray->direction.y * cos(angle * M_PI/180));
}

// int			map_width_for_y(t_data *data, int y)
// {
// 	if (y < data->map_y)
// 	{
// 		if (data->map[y] != NULL)
// 			return (ft_strlen(data->map[y]));
// 	}
// 	return (-1);
// }

// bool		its_a_wall(t_data *data, t_vec pos)
// {
// 	int	x = pos.x / 100;
// 	int	y = pos.y / 100;
// 	if(x < 0 || y < 0 || y > data->map_y || x > map_width_for_y(data, y))
// 	{
// 		write(2, "error in its a wall\n", 21);
// 		exit(1);
// 	}
// 	if (data->map[y][x] == '1')
// 		return (true);
// 	return (false);
// }


// static int	end_ray(t_data *data, t_vec pos)
// {
// 	if (pos.x < 0 || pos.y < 0 || 
// 			pos.y > (data->map_y * TILE) || 
// 			pos.x > (double) map_width_for_y(data, (pos.y / 100)) * TILE)
// 		return (2);
// 	return(its_a_wall(data, pos));
// }

int	end_ray(t_ray *ray)
{
	(void) ray;
	return (1);
}

t_xy	add_vector(t_xy v1, t_xy v2)
{
	t_xy	result;

	result.x = v1.x + v2.x;
	result.y = v2.y + v2.y;
	return (result);
}

t_xy	sub_vector(t_xy v1, t_xy v2)
{
	t_xy	result;

	result.x = v1.x - v2.x;
	result.y = v2.y - v2.y;
	return (result);
}

double v_raycast_cont(t_ray *ray, int check, double ratio)
{
	check = end_ray(ray);
	if (ray->tmp_direction.x < 0)
		ray->delta_x += 0.01;
	if (check == 0)
	{
		ratio = fabs(ray->tmp_direction.x) / TILE;
		if (ray->tmp_direction.x < 0)
			ray->next_cube.x = -TILE - 0.01;
		else
			ray->next_cube.x = TILE;
		ray->next_cube.y = ray->tmp_direction.y / ratio;
		while (check == 0)
		{
			ray->current_cube = add_vector(ray->current_cube, ray->next_cube);
			check = end_ray(ray);
		}
	}
	if (check == 2)
		return (INT_MAX);
	else
	{
		ray->v_intersection = ray->current_cube;
		ray->current_cube = sub_vector(ray->position, ray->current_cube);
		return (pythagoras(ray->current_cube));
	}
}

double	v_raycast(t_ray *ray)
{
	double		ratio;
	int			check;

	check = 0;
	if (ray->tmp_direction.x == 0)
		return (INT_MAX);
	if (ray->tmp_direction.x < 0)
		ray->delta_x = fmod(ray->position.x, TILE);
	else
		ray->delta_x = TILE - fmod(ray->position.x, TILE);
	ratio = fabs(ray->tmp_direction.x) / ray->delta_x;
	ray->delta_y = ray->tmp_direction.y / ratio;
	if (ray->tmp_direction.x < 0)
		ray->delta_x = (ray->delta_x * -1) - 0.01;
	ray->current_cube.x = ray->position.x + ray->delta_x;
	ray->current_cube.y = ray->position.y + ray->delta_y;
	return (v_raycast_cont(ray, check, ratio));
}

double h_raycast_cont(t_ray *ray, int check, double ratio)
{
	check = end_ray(ray);
	if (ray->tmp_direction.y < 0)
		ray->delta_y += 0.01;
	if (check == 0)
	{
		ratio = fabs(ray->tmp_direction.y) / TILE;
		if (ray->tmp_direction.y < 0)
			ray->next_cube.y = -TILE - 0.01;
		else
			ray->next_cube.y = TILE;
		ray->next_cube.x = ray->tmp_direction.x / ratio;
		while (check == 0)
		{
			ray->current_cube = add_vector(ray->current_cube, ray->next_cube);
			check = end_ray(ray);
		}
	}
	if (check == 2)
		return (INT_MAX);
	else
	{
		ray->h_intersection = ray->current_cube;
		ray->current_cube = sub_vector(ray->position, ray->current_cube);
		return (pythagoras(ray->current_cube));
	}
}

double	h_raycast(t_ray *ray)
{
	double		ratio;
	int			check;

	check = 0;
	if (ray->tmp_direction.y == 0)
		return (INT_MAX);
	if (ray->tmp_direction.y < 0)
		ray->delta_y = fmod(ray->position.y, TILE);
	else
		ray->delta_y = TILE - fmod(ray->position.y, TILE);
	ratio = fabs(ray->tmp_direction.y) / ray->delta_y;
	ray->delta_x = ray->tmp_direction.x / ratio;
	if (ray->tmp_direction.y < 0)
		ray->delta_y = (ray->delta_y * -1) - 0.01;
	ray->current_cube.x = ray->position.x + ray->delta_x;
	ray->current_cube.y = ray->position.y + ray->delta_y;
	return (h_raycast_cont(ray, check, ratio));	
}

void	single_ray(t_ray *ray)
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
		ray->distance = horizontal_rc;
	}
	else
	{
		if (ray->tmp_direction.x < 0)
			ray->current_wall = WEST_WALL;
		else
			ray->current_wall = EAST_WALL;
		ray->intersection = ray->v_intersection;
		ray->distance = vertical_rc;
	}
}

t_xy	normalize_vector(t_xy vector)
{
	t_xy	result;
	double	length;
	
	length = sqrt(vector.x * vector.x + vector.y * vector.y);
	result.x = vector.x / length;
	result.y = vector.y / length;
	return (result);
}

void	calculate_rad_diff(t_ray *ray)
{
	double	tmp_result;
	t_xy	tmp1;
	t_xy	tmp2;

	tmp1 = normalize_vector(ray->direction);
	tmp2 = normalize_vector(ray->tmp_direction);
	tmp_result = (tmp1.x * tmp2.x) + (tmp1.y * tmp2.y);
	ray->radiant_diff = acos(tmp_result);	
}

int	calculate_texture_x(t_ray *ray)
{
	double	texture_x_d;

	if (ray->current_wall == NORTH_WALL || ray->current_wall == SOUTH_WALL)
		texture_x_d = fmod(ray->intersection.x, TILE);
	else
		texture_x_d = fmod(ray->intersection.y, TILE);
	return ((int)(ray->walls[ray->current_wall].width * texture_x_d / 100));
}

void	draw_pixel_columns(t_ray *ray, int x)
{
	int		texture_x;
	int		texture_y;
	double	y_perc;
	int		y;
	t_img	*img;

	img = &ray->cube->img;
	texture_x = calculate_texture_x(ray);
	ray->wall_height = HEIGHT * TILE / ray->distance;
	ray->wall_offset = (HEIGHT - ray->wall_height) / 2;
	y = 0;
	while (y < HEIGHT)
	{
		if (y < ray->wall_offset)
			my_mlx_pixel_put(img, x, y, ray->ceiling_color);
		else if (y > ray->wall_height + ray->wall_offset)
			my_mlx_pixel_put(img, x, y, ray->floor_color);
		else
		{
			y_perc = (double)(y - ray->wall_offset) / ray->wall_height;
			texture_y = ray->walls[ray->current_wall].height * y_perc;
			my_mlx_pixel_put(img, x, y, my_mlx_pixel_get(ray->walls[ray->current_wall].img, texture_x, texture_y));
		}
		y++;
	}
}

void	raycasting(t_cube *cube)
{
	t_ray	*ray;
	int		i;

	ray = &cube->ray;
	i = 0;
	while (i < RAY_COUNT)
	{
		rotate_direction(ray, i);
		single_ray(ray);
		calculate_rad_diff(ray);
		ray->distance = ray->distance * cos(ray->radiant_diff);
		draw_pixel_columns(ray, i);
		i++;
	}
}