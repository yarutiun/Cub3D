#include "cub3d.h"

void    error_exit(char *message, t_cube *cube)
{
    ft_putstr_fd("Error\n", 2);
    ft_putstr_fd(message, 2);
    free_all(cube);
    exit(1);
}

void    file_error(t_cube *cube)
{
    error_exit("File not found\n", cube);
}

void    rgb_error(t_cube *cube)
{
    error_exit("Invalid RGB arguments\n", cube);
}

void    extension_error(t_cube *cube)
{
    error_exit("Invalid file extension\n", cube);    
}

void    init_elements_error(t_cube *cube)
{
    error_exit("Invalid elements on input file\n", cube);
}

void    argc_error(t_cube *cube)
{
    error_exit("Invalid number of arguments\n", cube);
}

void    error_double_n(t_cube *cube)
{
    error_exit("Empty line in map\n", cube);
}

void    map_row_error(t_cube *cube)
{
    error_exit("Open map\n", cube);
}

void    invalid_spaces_error(t_cube *cube)
{
    error_exit("Invalid space positon\n", cube);
}