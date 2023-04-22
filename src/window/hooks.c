#include "cub3d.h"

int	x_close(void)
{
	exit(EXIT_SUCCESS);
}

int	key_hooks(int keycode)
{
	if (keycode == 53)
		x_close();
	return (0);
}
