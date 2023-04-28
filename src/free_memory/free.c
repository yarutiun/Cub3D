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
	free_str(param->wall_path[0]);
	free_str(param->wall_path[1]);
	free_str(param->wall_path[2]);
	free_str(param->wall_path[3]);
	free_str(param->f);
	free_str(param->c);
	free_int_arr(param->f_rgb);
	free_int_arr(param->c_rgb);
}

void	close_fds(void)
{
	int	i;

	i = 3;
	while (i < MAX_FD)
	{
		close(i);
		i++;
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
	free_void_ptr(img->wall_ptr);
}

void	free_ray(t_ray *ray)
{
	(void) ray;
	// free_str(ray->placeholder);
}

void	free_all(t_cube *cube)
{
	free_param(&cube->param);
	if (cube->mlx.mlx_ptr && cube->mlx.window)
	{
		mlx_destroy_window(cube->mlx.mlx_ptr, cube->mlx.window);
		cube->mlx.window = NULL;
		free(cube->mlx.mlx_ptr);
		cube->mlx.mlx_ptr = NULL;
	}
	free_img(&cube->img);
	free_ray(&cube->ray);
	close_fds();
}
