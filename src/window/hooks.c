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

t_xy	add_vector(t_xy v1, t_xy v2)
{
	t_xy	result;

	result.x = v1.x + v2.x;
	result.y = v2.y + v2.y;
	return (result);
}

int	key_hooks(int keycode, t_rc *rc)
{
	char	**map;
	t_xy	rotation;
	double	old_plane_x;
	double	old_direction_x;
	double	rotation_speed;
	double	move_speed;
	// double	factor;

	map = rc->cube->param.map;
	rotation_speed = 0.15;
	move_speed = rotation_speed * (5 / 3);
	// factor = move_speed * 2;
	if (keycode == ESCAPE_KEY)
		x_close();
	else if (keycode == W_KEY)
	{
		// if (rc->direction.y >= 0.5) // East wall
		// 	factor *= 0.20;
		
		// if (rc->direction.y >= 0.5)
		// {
		// 	factor *= 0.20;
		// 	if (map[(int)(rc->position.x + rc->direction.x * factor)][(int)rc->position.y] != '1')
		// 	{
		// 		if (map[(int)rc->position.x][(int)(rc->position.y + rc->position.y * factor)] != '1')
		// 		{
		// 			rc->position.x += rc->direction.x * move_speed;
		// 			rc->position.y += rc->direction.y * move_speed;
		// 		}
		// 	}
		// }
		// else
		// {
			t_xy	projection;
			// projection = add_vector(rc->position, rc->camera_plane);
			projection.x = rc->position.x + rc->camera_plane.x;
			projection.y = rc->position.y + rc->camera_plane.y;

			printf("PosX: %f\n", rc->position.x);
			printf("PosY: %f\n", rc->position.y);
			// printf("CamX: %f\n", rc->camera_plane.x);
			// printf("CamY: %f\n", rc->camera_plane.y);
			printf("ProjectionX: %f\n", projection.x);
			printf("ProjectionY: %f\n", projection.y);
			// printf("DirX: %f\n", rc->direction.x);
			// printf("DirY: %f\n", rc->direction.y);
			printf("x: %d\n", (int)(projection.y + rc->direction.y * move_speed));
			printf("y: %d\n", (int)(projection.x + rc->direction.x * move_speed));
			printf("Posmap[x][y]: %c\n", map[(int)(rc->position.x + rc->direction.x * move_speed * 2)][(int)(rc->position.y + rc->direction.y * move_speed * 2)]);
			printf("map[x][y]: %c\n\n", map[(int)(projection.x + rc->direction.x * move_speed * 2)][(int)(projection.y + rc->direction.y * move_speed * 2)]);
			
			
			if (map[(int)(rc->position.x + rc->direction.x * move_speed)][(int)(rc->position.y + rc->direction.y * move_speed)] != '1')
			// if (map[(int)(projection.x + rc->direction.x * move_speed)][(int)(projection.y + rc->direction.y * move_speed)] != '1')
			{
				rc->position.x += rc->direction.x * move_speed;
				rc->position.y += rc->direction.y * move_speed;
			}
		// }
	}
	else if (keycode == S_KEY)
	{
		if (map[(int)(rc->position.x - rc->direction.x * move_speed)][(int)(rc->position.y - rc->direction.y * move_speed)] != '1')
		{
			rc->position.x -= rc->direction.x * move_speed;
			rc->position.y -= rc->direction.y * move_speed;
		}
	}
	if (keycode == A_KEY)
	{
		rotation = rotate_direction(rc->direction, 90);
		if (map[(int)(rc->position.x - rotation.x * move_speed)][(int)(rc->position.y - rotation.y * move_speed)])
		{
			if (map[(int)(rc->position.x - rotation.x * move_speed)][(int)(rc->position.y - rotation.y * move_speed)] != '1')
			{
				rc->position.x -= rotation.x * move_speed;
				rc->position.y -= rotation.y * move_speed;
			}
		}
	}
	if (keycode == D_KEY)
	{
		rotation = rotate_direction(rc->direction, -90);
		if (map[(int)(rc->position.x - rotation.x * move_speed)][(int)(rc->position.y - rotation.y * move_speed)])
		{
			if (map[(int)(rc->position.x - rotation.x * move_speed)][(int)(rc->position.y - rotation.y * move_speed)] != '1')
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
