#include "cub3d.h"

void	free_str(char *str)
{
	if (str)
		free(str);
	str = NULL;
}

void	free_int_arr(int *arr)
{
	if (arr)
		free(arr);
	arr = NULL;
}

void	free_double_str_ptr(char **arr)
{
	int	i;

	if (arr)
	{
		i = 0;
		while (arr[i])
		{
			if (arr[i])
				free(arr[i]);
			arr[i] = NULL;
			i++;
		}
		free(arr);
		arr = NULL;
	}
}

void	free_param(t_param *param)
{
	free_str(param->input_str);
	free_double_str_ptr(param->splitted_input);
	free_double_str_ptr(param->map);
	free_str(param->no);
	free_str(param->so);
	free_str(param->we);
	free_str(param->ea);
	free_str(param->f);
	free_str(param->c);
	free_int_arr(param->f_rgb);
	free_int_arr(param->c_rgb);
}

void	free_all(t_cube *cube)
{
	free_param(&cube->param);
	if (cube->mlx.mlx_ptr && cube->mlx.window)
	{
		mlx_destroy_window(cube->mlx.mlx_ptr, cube->mlx.window);
		cube->mlx.window = NULL;
	}
}

// void 	free_ptr(void *ptr, void free_func(void *))
// {
// 	if(ptr)
// 		free_func(ptr);
// }

// void	free_double_char_ptr(void *arr_p)
// {
// 	int	i;
// 	char **arr = arr_p;
// 	i = 0;
// 	while (arr[i])
// 	{
// 		free(arr[i]);
// 		arr[i] = NULL;
// 		i++;
// 	}
// 	free(arr);
// }

// void	free_param(t_param *param)
// {
// 	free_ptr(param->input_str, free);
// 	param->input_str = NULL;
// 	free_ptr(param->splitted_input, free_double_char_ptr);
// }