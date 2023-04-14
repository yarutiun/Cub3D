#include "cub3d.h"

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