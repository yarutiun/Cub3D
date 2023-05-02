#include "cub3d.h"

int	array_size(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		i++;
	}
	return (i);
}

char	*get_next_line(int fd)
{
	int		i;
	int		readed;
	char	c;
	char	*buff;

	i = 0;
	buff = malloc(sizeof(char) * 100);
	readed = 1;
	while (readed > 0)
	{
		readed = read(fd, &c, 1);
		buff[i++] = c;
		if (c == '\n')
			break ;
	}
	if ((!buff[i - 1] && !readed) || readed == -1)
		return (free(buff), NULL);
	if (buff[i - 1] == '\n')
	{
		buff[i - 1] = '\0';
		return (buff);
	}
	buff[i] = '\0';
	return (buff);
}

int	rgb_to_hex(int *rgb)
{
	double	color;

	color = 0 << 24 | rgb[0] << 16 | rgb[1] << 8 | rgb[2];
	return (color);
}

void	init_mlx(t_cube *cube)
{
	t_mlx	*mlx;

	mlx = &cube->mlx;
	mlx->mlx_ptr = NULL;
	mlx->window = NULL;
}

void	player_error_if(t_cube *cube, int flag)
{
	if (flag == 0)
		player_error(cube, "No players on the map\n");
	else if (flag > 1)
		player_error(cube, "Too many players on the map\n");
}
