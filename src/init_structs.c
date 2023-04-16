#include "cub3d.h"

void	init_structs(t_cube *cube)
{
	t_param	*param;

	param = &cube->param;
	param->cube = cube;
	param->file_input = NULL;
	param->input_str = NULL;
	param->splitted_input = NULL;
	param->path = NULL;
	param->no = NULL;
	param->so = NULL;
	param->we = NULL;
	param->ea = NULL;
	param->f = NULL;
	param->c = NULL;
	param->map = NULL;
}
