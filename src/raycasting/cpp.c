#include "cub3d.h"

void	calculate_deltas(t_rc *rc, int x)
{
	rc->cameraX = 2 * x / (double)WIDTH - 1;
	rc->ray_dir.x = rc->direction.x + rc->camera_plane.x * rc->cameraX;
	rc->ray_dir.y = rc->direction.y + rc->camera_plane.y * rc->cameraX;
	if (rc->ray_dir.x == 0)
		rc->delta_dist.x = INT_MAX;
	else
		rc->delta_dist.x = fabs(1 / rc->ray_dir.x);

	if (rc->delta_dist.y == 0)
		rc->delta_dist.y = INT_MAX;
	else
		rc->delta_dist.y = fabs(1 / rc->ray_dir.y);
}

void	calculate_side_distance(t_rc *rc)
{
	rc->map.x = (int)rc->position.x; // Use floor?
	rc->map.y = (int)rc->position.y; // Use floor?
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
			if (rc->cube->param.map[rc->map.x][rc->map.y] > 0)
				hit = 1;	
		}
	}
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
		x++;
	}
	ft_putstr_fd("Test\n", 1);
}

void	init_starting_values(t_cube *cube)
{
	t_rc	*rc;

	rc = &cube->rc;
	rc->position.x = 22;
	rc->position.y = 12;
	rc->direction.x = -1;
	rc->direction.y = 0;
	rc->camera_plane.x = 0;
	rc->camera_plane.y = 0.66;
}
