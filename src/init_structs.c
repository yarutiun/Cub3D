#include "cub3d.h"

void	init_param(t_cube *cube)
{
	t_param	*param;

	param = &cube->param;
	param->input_str = NULL;
	param->splitted_input = NULL;
	param->wall_path[0] = NULL;
	param->wall_path[1] = NULL;
	param->wall_path[2] = NULL;
	param->wall_path[3] = NULL;
	param->f = NULL;
	param->c = NULL;
	param->f_rgb = malloc(sizeof(int) * 3);
	param->c_rgb = malloc(sizeof(int) * 3);
	param->map = NULL;
	param->new_map = NULL;
}

void	init_mlx(t_cube *cube)
{
	t_mlx	*mlx;

	mlx = &cube->mlx;
	mlx->mlx_ptr = NULL;
	mlx->window = NULL;
}

void	init_img(t_cube *cube)
{
	t_img	*img;

	img = &cube->img;
	img->img = NULL;
	img->address = NULL;
	img->bits_per_pixel = 0;
	img->line_length = 0;
	img->endian = 0;
}

void init_rc(t_cube *cube)
{
	t_rc	*rc;

	rc = &cube->rc;
	rc->position.x = 0;
	rc->position.y = 0;
	rc->direction.x = 0;
	rc->direction.y = 0;
	rc->camera_plane.x = 0;
	rc->camera_plane.y = 0;
	rc->camera_x = 0;
	rc->ray_dir.x = 0;
	rc->ray_dir.y = 0;
	rc->map.x = 0;
	rc->map.y = 0;
	rc->side_dist.x = 0;
	rc->side_dist.y = 0;
	rc->delta_dist.x = 0;
	rc->delta_dist.y = 0;
	rc->step.x = 0;
	rc->step.y = 0;
	rc->side = 0;
	rc->perp_wall_dist = 0;
	rc->line_height = 0;
	rc->draw_start = 0;
	rc->draw_end = 0;
	rc->pitch = 0;
	rc->wall_type = 0;
	rc->texture.x = 0;
	rc->texture.y = 0;
	rc->texture_step = 0;
	rc->texture_position = 0;
	rc->floor_color = 0;
	rc->ceiling_color = 0;
	rc->player_char = '\0';
}

void	init_structs(t_cube *cube)
{
	cube->param.cube = cube;
	init_param(cube);
	cube->mlx.cube = cube;
	init_mlx(cube);
	cube->img.cube = cube;
	init_img(cube);
	cube->rc.cube = cube;
	init_rc(cube);
}
