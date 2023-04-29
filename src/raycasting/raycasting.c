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
	double	x;
	double	y;

	x = rc->direction.x;
	y = rc->direction.y;
	if (rc->side == 0)
	{
		if (rc->ray_dir.x <= 0)
			rc->wall_type = NORTH_WALL;
		else
			rc->wall_type = SOUTH_WALL;
	}
	else
	{
		if (rc->ray_dir.y >= 0)
			rc->wall_type = WEST_WALL;
		else
			rc->wall_type = EAST_WALL;
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
	rc->texture_position = (rc->draw_start - rc->pitch - HEIGHT / 2 + rc->line_height / 2) * rc->texture_step;
}

void	draw_vertical_line(t_rc *rc, int x)
{
	int				y;
	unsigned int	wall_color;

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
			rc->texture.y = (int)rc->texture_position & (rc->walls[rc->wall_type].height - 1);
			rc->texture_position += rc->texture_step;
			wall_color = my_mlx_pixel_get(rc->walls[rc->wall_type].img, rc->texture.x, rc->texture.y);
			my_mlx_pixel_put(&rc->cube->img, x, y, wall_color);
		}
		y++;
	}
}

void	fix_fisheye(t_rc *rc)
{
	if (rc->side == 0)
		rc->perp_wall_dist = rc->side_dist.x - rc->delta_dist.x;
	else
		rc->perp_wall_dist = rc->side_dist.y - rc->delta_dist.y;
	rc->line_height = (int)(HEIGHT / rc->perp_wall_dist);
	rc->draw_start = -rc->line_height / 2 + HEIGHT / 2 + rc->pitch;
	if (rc->draw_start < 0)
		rc->draw_start = 0;
	rc->draw_end = rc->line_height / 2 + HEIGHT / 2 + rc->pitch;
	if (rc->draw_end >= HEIGHT)
		rc->draw_end = HEIGHT - 1;
}

void	perform_dda(t_rc *rc)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (rc->side_dist.x < rc->side_dist.y)
		{
			rc->side_dist.x += rc->delta_dist.x;
			rc->map.x += rc->step.x;
			rc->side = 0;
		}
		else
		{
			rc->side_dist.y += rc->delta_dist.y;
			rc->map.y += rc->step.y;
			rc->side = 1;
		}
		if (rc->cube->param.map[rc->map.x][rc->map.y])
		{
			if (rc->cube->param.map[rc->map.x][rc->map.y] > '0')
				hit = 1;
		}
	}
}

void	calculate_side_distance(t_rc *rc)
{
	rc->map.x = (int)rc->position.x;
	rc->map.y = (int)rc->position.y;
	if (rc->ray_dir.x < 0)
	{
		rc->step.x = -1;
		rc->side_dist.x = (rc->position.x - rc->map.x) * rc->delta_dist.x;
	}
	else
	{
		rc->step.x = 1;
		rc->side_dist.x = (rc->map.x + 1.0 - rc->position.x) * rc->delta_dist.x;
	}
	if (rc->ray_dir.y < 0)
	{
		rc->step.y = -1;
		rc->side_dist.y = (rc->position.y - rc->map.y) * rc->delta_dist.y;
	}
	else
	{
		rc->step.y = 1;
		rc->side_dist.y = (rc->map.y + 1.0 - rc->position.y) * rc->delta_dist.y;
	}
}

void	calculate_deltas(t_rc *rc, int x)
{
	rc->cameraX = 2 * x / (double)WIDTH - 1;
	rc->ray_dir.x = rc->direction.x + rc->camera_plane.x * rc->cameraX;
	rc->ray_dir.y = rc->direction.y + rc->camera_plane.y * rc->cameraX;
	if (rc->ray_dir.x == 0)
		rc->delta_dist.x = INT_MAX;
	else
		rc->delta_dist.x = fabs(1 / rc->ray_dir.x);

	if (rc->ray_dir.y == 0)
		rc->delta_dist.y = INT_MAX;
	else
		rc->delta_dist.y = fabs(1 / rc->ray_dir.y);
}

void	raycasting(t_cube *cube)
{
	t_rc	*rc;
	int		x;

	rc = &cube->rc;
	x = 0;
	while (x < WIDTH)
	{
		calculate_deltas(rc, x);
		calculate_side_distance(rc);
		perform_dda(rc);
		fix_fisheye(rc);
		draw_vertical_line(rc, x);
		x++;
	}
}

void	init_texture(t_cube *cube, int type)
{
	t_wall	*wall;

	wall = &cube->rc.walls[type];
	wall->img = malloc(sizeof(t_img));
	wall->img->img = mlx_xpm_file_to_image(cube->mlx.mlx_ptr, cube->param.wall_path[type], &wall->width, &wall->height);
	if (!wall->img)
	{
		free(wall->img);
		texture_not_loaded_error(cube);
	}
	wall->img->address = mlx_get_data_addr(wall->img->img, &wall->img->bits_per_pixel,
				&wall->img->line_length, &wall->img->endian);
}

void	load_textures(t_cube *cube)
{
	t_rc	*rc;

	rc = &cube->rc;
	rc->walls[NORTH_WALL].height = 128; // Parsing or constant?
	rc->walls[NORTH_WALL].width = 128; // Parsing or constant?
	rc->walls[SOUTH_WALL].height = 128; // Parsing or constant?
	rc->walls[SOUTH_WALL].width = 128; // Parsing or constant?
	rc->walls[WEST_WALL].height = 128; // Parsing or constant?
	rc->walls[WEST_WALL].width = 128; // Parsing or constant?
	rc->walls[EAST_WALL].height = 128; // Parsing or constant?
	rc->walls[EAST_WALL].width = 128; // Parsing or constant?
	
	init_texture(cube, NORTH_WALL);
	init_texture(cube, SOUTH_WALL);
	init_texture(cube, WEST_WALL);
	init_texture(cube, EAST_WALL);
}

void	init_starting_values(t_cube *cube)
{
	t_rc	*rc;

	rc = &cube->rc;
	//check_player
	rc->position.x = 3; //Position of player char
	rc->position.y = 3; //Position of player char
	rc->direction.x = 1; //NSWE
	rc->direction.y = 0; //NSWE
	rc->camera_plane.x = 0; //Calc after direction
	rc->camera_plane.y = 0.66;  //Calc after direction

	rc->pitch = 100; // Constant

	//Use f_rgb and c_rgb
	rc->floor_color = 0x0000CC66; // init_starting_values
	rc->ceiling_color = 0x00000000; // init_starting_values

	//Load map
	// char **map 

	// SOUTH
	// DirX = 1
	// DirY = 0
	// cPlaneX = 0
	// cPlaneY = 0.66 

	// WEST
	// DirX = 0
	// DirY = 1
	// cPlaneX = -0.66
	// cPlaneY = 0

	// NORTH
	// DirX = -1
	// DirY = 0
	// cPlaneX = 0
	// cPlaneY = -0.66

	// EAST
	// DirX = 0
	// DirY = -1
	// cPlaneX = 0.66
	// cPlaneY = 0
}