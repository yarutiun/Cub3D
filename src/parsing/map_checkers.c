#include "cub3d.h"

void	check_map_double_n(char *input, t_cube *cube)
{
	int	count;
	int	flag;

	count = 0;
	flag = 0;
	while (flag < 6)
	{
		if (ft_isalpha(input[count]))
		{
			while (input[count])
			{
				if (input[count] == '\n')
				{
					flag++;
					break ;
				}
				count++;
			}
		}
		count++;
	}
	while (input[count])
	{
		if (input[count] == ' ' || input[count] == '1' || input[count] == '0')
			break ;
		count++;
	}
	while (input[count])
	{
		if (input[count] == '\n' && input[count + 1] \
		&& input[count + 1] == '\n')
			error_double_n(cube);
		count++;
	}
}

void	check_map_row(char **splitted_input, t_cube *cube)
{
	int	i;
	int	last_i;

	i = 6;
	while (splitted_input[i])
	{
		last_i = ft_strlen(splitted_input[i]) - 1;
		if (splitted_input[i][last_i] == '0')
			map_row_error(cube);
		else if (splitted_input[i][0] == '0')
			map_row_error(cube);
		i++;
	}
}

void	check_invalid_spaces(char **map, t_cube *cube)
{
	int	i;
	int	j;

	i = 0;
	while (i < array_size(map))
	{
		j = 0;
		while (j < (int)ft_strlen(map[i]))
		{
			if (map[i][j] == '0')
			{
				if (map[i][j + 1] && map[i][j + 1] == ' ')
					invalid_spaces_error(cube);
				if (map[i][j - 1] && map[i][j - 1] == ' ')
					invalid_spaces_error(cube);
				if (map[i + 1][j] && map[i + 1][j] == ' ')
					invalid_spaces_error(cube);
				if (map[i - 1][j] && map[i - 1][j] == ' ')
					invalid_spaces_error(cube);
			}
			j++;
		}
		i++;
	}
}

//Returns 1 if any other characters detected in map but 01NSEW
//Retunrs 0 if check went successful
void	check_forbidden_chars(char **map, t_cube *cube)
{
	int		i;
	int		j;
	char	*symbols;

	symbols = "01NSEW ";
	i = 0;
	while (i < array_size(map))
	{
		j = 0;
		while (j < (int)ft_strlen(map[i]))
		{
			if (ft_isprint(map[i][j]))
			{
				if (ft_strchr(symbols, map[i][j]) == NULL)
					forbidden_chars_error(cube);
			}
			j++;
		}
		i++;
	}
}
