#include "cub3d.h"


void	free_double_char_ptr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (arr[i])
			free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
}

void	free_param(t_param *param)
{
	if (param->input_str)
		free(param->input_str);
	param->input_str = NULL;
	if (param->splitted_input)
		free_double_char_ptr(param->splitted_input);
	param->splitted_input = NULL;
	if (param->no)
		free(param->no);
	param->no = NULL;
	if (param->so)
		free(param->so);
	param->so = NULL;
	if (param->we)
		free(param->we);
	param->we = NULL;
	if (param->ea)
		free(param->ea);
	param->ea = NULL;
	if (param->f)
		free(param->f);
	param->f = NULL;
	if (param->c)
		free(param->c);
	param->c = NULL;
}

void	free_all(t_cube *cube)
{
	free_param(&cube->param);
}
