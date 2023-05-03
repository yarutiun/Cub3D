#include "cub3d.h"

int	x_close(void)
{
	exit(0);
}

void	front_back_movement(t_rc *rc, char **map, int key)
{
	double		factor;
	t_xy_int	delta;

	if (key == W_KEY)
	{
		factor = MOVE_SPEED * 2;
		delta.x = (int)(rc->position.x + rc->direction.x * factor);
		delta.y = (int)(rc->position.y + rc->direction.y * factor);
		if (map[delta.x][(int)rc->position.y] != '1')
			rc->position.x += rc->direction.x * MOVE_SPEED;
		if (map[(int)rc->position.x][delta.y] != '1')
			rc->position.y += rc->direction.y * MOVE_SPEED;
	}
	else if (key == S_KEY)
	{
		factor = MOVE_SPEED;
		delta.x = (int)(rc->position.x - rc->direction.x * factor);
		delta.y = (int)(rc->position.y - rc->direction.y * factor);
		if (map[delta.x][(int)rc->position.y] != '1')
			rc->position.x -= rc->direction.x * MOVE_SPEED;
		if (map[(int)rc->position.x][delta.y] != '1')
			rc->position.y -= rc->direction.y * MOVE_SPEED;
	}
}

t_xy	rotate_direction(t_xy dir, double ang)
{
	t_xy	tmp;

	tmp.x = dir.x;
	tmp.y = dir.y;
	dir.x = (tmp.x * cos(ang * M_PI / 180)) - (tmp.y * sin(ang * M_PI / 180));
	dir.y = (tmp.x * sin(ang * M_PI / 180)) + (tmp.y * cos(ang * M_PI / 180));
	return (dir);
}

void	left_right_movement(t_rc *rc, char **map, int key)
{
	t_xy		rotation;
	t_xy_int	delta;

	delta.x = (int)(rc->position.x - rotation.x * MOVE_SPEED);
	delta.y = (int)(rc->position.y - rotation.y * MOVE_SPEED);
	if (key == A_KEY)
		rotation = rotate_direction(rc->direction, 90);
	else if (key == D_KEY)
		rotation = rotate_direction(rc->direction, -90);
	if (map[delta.x][delta.y])
	{
		if (map[delta.x][delta.y] != '1')
		{
			rc->position.x -= rotation.x * MOVE_SPEED;
			rc->position.y -= rotation.y * MOVE_SPEED;
		}
	}
}

void	rotate_camera(t_rc *rc, int key)
{
	double	angle;
	double	old_plane_x;
	double	old_direction_x;

	angle = 0;
	if (key == LEFT_KEY)
		angle = -ROTATION_SPEED;
	else if (key == RIGHT_KEY)
		angle = ROTATION_SPEED;
	old_direction_x = rc->direction.x;
	rc->direction.x = rc->direction.x * cos(angle) - \
						rc->direction.y * sin(angle);
	rc->direction.y = old_direction_x * sin(angle) + \
						rc->direction.y * cos(angle);
	old_plane_x = rc->camera_plane.x;
	rc->camera_plane.x = rc->camera_plane.x * cos(angle) - \
						rc->camera_plane.y * sin(angle);
	rc->camera_plane.y = old_plane_x * sin(angle) + \
						rc->camera_plane.y * cos(angle);
}
