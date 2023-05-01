#include "cub3d.h"

void	init_texture(t_cube *cube, int type)
{
	t_wall	*wall;

	wall = &cube->rc.walls[type];
	wall->img = malloc(sizeof(t_img));
	wall->img->img = mlx_xpm_file_to_image(cube->mlx.mlx_ptr, \
					cube->param.wall_path[type], &wall->width, &wall->height);
	if (!wall->img)
	{
		free(wall->img);
		texture_not_loaded_error(cube);
	}
	wall->img->address = mlx_get_data_addr(wall->img->img, \
							&wall->img->bits_per_pixel, \
							&wall->img->line_length, &wall->img->endian);
}

void	load_textures(t_cube *cube)
{
	t_rc	*rc;

	rc = &cube->rc;
	init_texture(cube, NORTH_WALL);
	init_texture(cube, SOUTH_WALL);
	init_texture(cube, WEST_WALL);
	init_texture(cube, EAST_WALL);
	rc->walls[NORTH_WALL].height = TEXTURE_HEIGHT;
	rc->walls[NORTH_WALL].width = TEXTURE_WIDTH;
	rc->walls[SOUTH_WALL].height = TEXTURE_HEIGHT;
	rc->walls[SOUTH_WALL].width = TEXTURE_WIDTH;
	rc->walls[WEST_WALL].height = TEXTURE_HEIGHT;
	rc->walls[WEST_WALL].width = TEXTURE_WIDTH;
	rc->walls[EAST_WALL].height = TEXTURE_HEIGHT;
	rc->walls[EAST_WALL].width = TEXTURE_WIDTH;
}

void	init_starting_values(t_cube *cube)
{
	t_rc	*rc;

	rc = &cube->rc;
	rc->floor_color = rgb_to_hex(cube->param.f_rgb);
	rc->ceiling_color = rgb_to_hex(cube->param.c_rgb);
	if (rc->player_char == 'N')
	{
		rc->direction.x = 1;
		rc->camera_plane.y = CAMERA_PLANE;
	}
	if (rc->player_char == 'S')
	{
		rc->direction.x = -1;
		rc->camera_plane.y = -CAMERA_PLANE;
	}
	if (rc->player_char == 'W')
	{
		rc->direction.y = -1;
		rc->camera_plane.x = CAMERA_PLANE;
	}
	if (rc->player_char == 'E')
	{
		rc->direction.y = 1;
		rc->camera_plane.x = -CAMERA_PLANE;
	}
}
