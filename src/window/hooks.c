#include "cub3d.h"

t_xy	rotate_direction(t_xy dir, double ang)
{
	t_xy	tmp;

	tmp.x = dir.x;
	tmp.y = dir.y;
	dir.x = (tmp.x * cos(ang * M_PI / 180)) - (tmp.y * sin(ang * M_PI / 180));
	dir.y = (tmp.x * sin(ang * M_PI / 180)) + (tmp.y * cos(ang * M_PI / 180));
	return (dir);
}

int	x_close(void)
{
	exit(0);
}

int	key_hooks(int keycode, t_rc *rc)
{
	char	**map;
	t_xy	rotation;
	double	old_plane_x;
	double	old_direction_x;
	double	rotation_speed;
	double	move_speed;
	double	factor;

	map = rc->cube->param.map;
	rotation_speed = 0.15;
	move_speed = rotation_speed * (5 / 3);
	factor = move_speed * 1;
	if (keycode == ESCAPE_KEY)
		x_close();
	else if (keycode == W_KEY)
	{
		if (map[(int)(rc->position.x + rc->direction.x * factor)][(int)(rc->position.y + rc->position.y * factor)])
		{
			if (map[(int)(rc->position.x + rc->direction.x * factor)][(int)rc->position.y] == '0')
			{
				if (map[(int)rc->position.x][(int)(rc->position.y + rc->position.y * factor)] == '0')
				{
					rc->position.x += rc->direction.x * move_speed;
					rc->position.y += rc->direction.y * move_speed;
				}
			}
		}
	}
	else if (keycode == S_KEY)
	{
		if (map[(int)(rc->position.x - rc->direction.x * factor)][(int)(rc->position.y - rc->position.y * factor)])
		{
			if (map[(int)(rc->position.x - rc->direction.x * factor)][(int)rc->position.y] == '0')
			{
				if (map[(int)rc->position.x][(int)(rc->position.y - rc->position.y * factor)] == '0')
				{
					rc->position.x -= rc->direction.x * move_speed;
					rc->position.y -= rc->direction.y * move_speed;
				}
			}
		}
	}
	if (keycode == A_KEY)
	{
		rotation = rotate_direction(rc->direction, 90);
		if (map[(int)(rc->position.x - rotation.x * factor)][(int)(rc->position.y - rotation.y * factor)])
		{
			if (map[(int)(rc->position.x - rotation.x * factor)][(int)(rc->position.y - rotation.y * factor)] == '0')
			{
				rc->position.x -= rotation.x * move_speed;
				rc->position.y -= rotation.y * move_speed;
			}
		}
	}
	if (keycode == D_KEY)
	{
		rotation = rotate_direction(rc->direction, -90);
		if (map[(int)(rc->position.x - rotation.x * factor)][(int)(rc->position.y - rotation.y * factor)])
		{
			if (map[(int)(rc->position.x - rotation.x * factor)][(int)(rc->position.y - rotation.y * factor)] == '0')
			{
				rc->position.x -= rotation.x * move_speed;
				rc->position.y -= rotation.y * move_speed;
			}
		}
	}
	if (keycode == LEFT_KEY)
	{
		old_direction_x = rc->direction.x;
		rc->direction.x = rc->direction.x * cos(-rotation_speed) - rc->direction.y * sin(-rotation_speed);
		rc->direction.y = old_direction_x * sin(-rotation_speed) + rc->direction.y * cos(-rotation_speed);
		old_plane_x = rc->camera_plane.x;
		rc->camera_plane.x = rc->camera_plane.x * cos(-rotation_speed) - rc->camera_plane.y * sin(-rotation_speed);
		rc->camera_plane.y = old_plane_x * sin(-rotation_speed) + rc->camera_plane.y * cos(-rotation_speed);
	}
	if (keycode == RIGHT_KEY)
	{
		old_direction_x = rc->direction.x;
		rc->direction.x = rc->direction.x * cos(rotation_speed) - rc->direction.y * sin(rotation_speed);
		rc->direction.y = old_direction_x * sin(rotation_speed) + rc->direction.y * cos(rotation_speed);
		old_plane_x = rc->camera_plane.x;
		rc->camera_plane.x = rc->camera_plane.x * cos(rotation_speed) - rc->camera_plane.y * sin(rotation_speed);
		rc->camera_plane.y = old_plane_x * sin(rotation_speed) + rc->camera_plane.y * cos(rotation_speed);
	}
	render_window(rc->cube);
	return (0);
}
