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

void	free_void_ptr(void *var)
{
	if (var)
		free(var);
	var = NULL;
}

void	free_img(t_img *img)
{
	free_void_ptr(img->img);
	free_str(img->address);
}
