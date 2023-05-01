#include "cub3d.h"

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
	free_double_str_ptr(param->new_map);
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
	close_fds();
}
