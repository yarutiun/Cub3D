#include "cub3d.h"

int	key_hooks(int keycode, t_rc *rc)
{
	char	**map;

	map = rc->cube->param.new_map;
	if (keycode == ESCAPE_KEY)
		x_close();
	else if (keycode == W_KEY || keycode == S_KEY)
		front_back_movement(rc, map, keycode);
	else if (keycode == A_KEY || keycode == D_KEY)
		left_right_movement(rc, map, keycode);
	if (keycode == LEFT_KEY || keycode == RIGHT_KEY)
		rotate_camera(rc, keycode);
	render_window(rc->cube);
	return (0);
}
