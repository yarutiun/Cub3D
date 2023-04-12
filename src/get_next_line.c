#include "cub3d.h"

char	*read_file(int fd, char *stash)
{
	int		bytes_read;
	char	*buff;

	bytes_read = 1;
	buff = malloc((BUFFER_SIZE + 1) * (sizeof(char)));
	if (!buff)
	{
		return (NULL);
	}
	while (!ft_strchr(stash, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (buff);
			return (NULL);
		}
		buff[bytes_read] = '\0';
		stash = ft_strjoin(stash, buff);
	}
	free(buff);
	return (stash);
}

char	*get_return(char *stash)
{
	int		i;
	char	*ret_line;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	ret_line = (char *)malloc(sizeof(char) * (i + 2));
	if (!ret_line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		ret_line[i] = stash[i];
		i ++;
	}
	if (stash[i] == '\n')
	{
		ret_line[i] = stash[i];
		i++;
	}
	ret_line[i] = '\0';
	return (ret_line);
}

char	*get_new_stash(char *stash)
{
	int		counter;
	int		counter2;
	char	*new_stash;

	counter = 0;
	while (stash[counter] && stash[counter] != '\n')
		counter++;
	if (!stash[counter])
	{
		free(stash);
		return (NULL);
	}
	new_stash = (char *)malloc(sizeof(char) * (ft_strlen(stash) - counter + 1));
	if (!new_stash)
		return (NULL);
	counter ++;
	counter2 = 0;
	while (stash[counter])
		new_stash[counter2++] = stash[counter++];
	new_stash[counter2] = '\0';
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	char		*ret;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_file(fd, stash);
	if (!stash)
		return (NULL);
	ret = get_return(stash);
	stash = get_new_stash(stash);
	return (ret);
}
