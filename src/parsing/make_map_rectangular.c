#include "cub3d.h"

//This function takes our ".cub" map as an input
//Opens a file and copies the map with all symbols to char **map
//Returns Null (almost impossible) or a filled map
//Needs tests, also not sure is sets last map[i] to NULL
void	assign_map(char **splitted_input, t_cube *cube)
{
	int	i;
	int	j;

	i = 6;
	j = 0;
	while (splitted_input[i])
	{
		i++;
		j++;
	}
	i = 6;
	cube->param.map = malloc(sizeof(char *) * (j + 1));
	cube->param.map[j] = NULL;
	j = 0;
	while (splitted_input[i])
	{
		cube->param.map[j] = ft_strdup(splitted_input[i]);
		i++;
		j++;
	}
}

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

void	allocate_map_with_spaces(t_param *param)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = array_size(param->map);
	param->longest_row_size = find_longest_row(param->map);
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
	j = array_size(param->map);
	param->new_map[j - 1][param->longest_row_size - 1] = '\0';
}

void	replace_spaces(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == ' ')
				map[i][j] = '1';
			j++;
		}
		i++;
	}
	map[array_size(map) - 1][ft_strlen(map[0]) - 1] = '1';
}
