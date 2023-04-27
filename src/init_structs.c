#include "cub3d.h"

void	init_param(t_cube *cube)
{
	t_param	*param;

	param = &cube->param;
	param->input_str = NULL;
	param->splitted_input = NULL;
	// param->wall_path = NULL;
	param->f = NULL;
	param->c = NULL;
	param->f_rgb = malloc(sizeof(int) * 3);
	param->c_rgb = malloc(sizeof(int) * 3);
	param->map = NULL;
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
	img->wall_ptr = NULL;
}

void	init_ray(t_cube *cube)
{
	t_ray	*ray;

	ray = &cube->ray;
	ray->distance = 0;
	ray->radiant_diff = 0;
	ray->ceiling_color = 0;
	ray->floor_color = 0;
	ray->current_wall = 0;
	ray->direction.x = 0; // Parsing NSWE - When N = 0
	ray->direction.y = 1; // Parsing NSWE - When N = 1
	ray->tmp_direction.x = 0;
	ray->tmp_direction.y = 0;
	ray->intersection.x = 0;
	ray->intersection.y = 0;
	ray->h_intersection.x = 0;
	ray->h_intersection.y = 0;
	ray->v_intersection.x = 0;
	ray->v_intersection.y = 0;
	ray->position.x = 0; // Parsing - starting position
	ray->position.y = 0; // Parsing- starting position
	ray->delta_x = 0;
	ray->delta_y = 0;
	ray->current_cube.x = 0;
	ray->current_cube.y = 0;
	ray->next_cube.x = 0;
	ray->next_cube.y = 0;
	ray->wall_height = 0;
	ray->wall_offset = 0;
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
	rc->cameraX = 0;
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
}

void	init_structs(t_cube *cube)
{
	cube->param.cube = cube;
	init_param(cube);
	cube->mlx.cube = cube;
	init_mlx(cube);
	cube->img.cube = cube;
	init_img(cube);
	cube->ray.cube = cube;
	init_ray(cube);
	cube->rc.cube = cube;
	init_rc(cube);
}
