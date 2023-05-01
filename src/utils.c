#include "cub3d.h"

int     array_size(char **arr)
{
    int i;

    i = 0;
    while (arr[i])
    {
        i++;
    }
    return (i);
}

void	print_double_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
    {
		printf("%s\n", arr[i]);
        i++;
    }
}

char *get_next_line(int fd)
{
	int i;
	int readed;
	char c;
	char *buff;

	i = 0;
	buff = malloc(sizeof(char) * 100);
	while((readed = read(fd, &c, 1)) > 0)
	{
		buff[i++] = c;
		if(c == '\n')
			break;
	}
	if((!buff[i - 1] && !readed) || readed == -1)
	{
		free(buff);
		return(NULL);
	}
	if(buff[i - 1] == '\n')
	{
		buff[i - 1] = '\0';
		return(buff);	
	}
	buff[i] = '\0';
	return(buff);
}

int	rgb_to_hex(int *rgb)
{
	double	color;

	color = 0 << 24 | rgb[0] << 16 | rgb[1] << 8 | rgb[2];
	return (color);
}