#include "cub3d.h"


void 	free_ptr(void *ptr, void free_func(void *))
{
	if(ptr)
		free_func(ptr);
}

void	free_double_char_ptr(void *arr_p)
{
	int	i;
	char **arr = arr_p;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
}

void	free_param(t_param *param)
{
	free_ptr(param->input_str, free);
	param->input_str = NULL;
	free_ptr(param->splitted_input, free_double_char_ptr);
	free_ptr(param->no, free);
	free_ptr(param->so, free);
	free_ptr(param->we, free);
	free_ptr(param->ea, free);
	free_ptr(param->f, free);
	free_ptr(param->c, free);
}

void	free_all(t_cube *cube)
{
	free_param(&cube->param);
}
