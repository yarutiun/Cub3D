#include "cub3d.h"

int	find_longest_row(char **map)
{
	int	i;
	int	j;
	int	longest;

	i = 0;
	j = 0;
	longest = j;
	while (map[i])
	{
		while (map[i][j])
		{
			j++;
			if (longest <= j)
			{
				longest = j;
			}
		}
		i++;
	}
	return (longest);
}

void	allocate_map_memory(t_param *param)
{
	int	j;
	int	i;

	i = 0;
	j = array_size(param->map);
	param->new_map = malloc(sizeof(char *) * j + 1);
	param->new_map[j] = NULL;
	if (!param->new_map)
		free_all(param->cube);
	while (i < j)
	{
		param->new_map[i] = malloc(sizeof(char) * param->longest_row_size + 1);
		param->new_map[i][param->longest_row_size] = '\0';
		i++;
	}
}

void	add_spaces_to_map(t_param *param)
{
	int	j;
	int	i;
	int	len;

	j = array_size(param->map);
	i = 0;
	while (i < j)
	{
		ft_strcpy(param->new_map[i], param->map[i]);
		len = ft_strlen(param->map[i]);
		while (len < param->longest_row_size)
		{
			param->new_map[i][len] = ' ';
			len++;
		}
		i++;
	}
	param->new_map[j - 1][param->longest_row_size - 1] = '\0';
}

void	allocate_map_with_spaces(t_param *param)
{
	param->longest_row_size = find_longest_row(param->map);
	allocate_map_memory(param);
	add_spaces_to_map(param);
}
