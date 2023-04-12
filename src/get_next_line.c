#include "cub3d.h"

bool	free_get_next_line(char *buff, int i, int readed)
{
	if ((!buff[i - 1] && !readed) || readed == -1)
	{
		free(buff);
		return (true);
	}
	return (false);
}

char	*get_next_line(int fd)
{
	int		i;
	int		readed;
	char	c;
	char	*buff;

	i = 0;
	buff = malloc(sizeof(char) * 100);
	while (1)
	{
		readed = read(fd, &c, 1);
		if (readed > 0)
		{
			buff[i++] = c;
			if (c == '\n')
				break ;
		}
		else
			break ;
	}
	if (free_get_next_line(buff, i, readed))
		return (NULL);
	buff[i] = '\0';
	return (buff);
}
