#include "cub3d.h"

char *read_from_file(char *path)
{
    int     fd;
    char    *output;
    int     counter;
    int     rd;

    fd = 0;
    rd = 0;
    counter = 0;
    fd = open(path, O_RDONLY);
    if(fd < 0)
        return(NULL);
    output = ft_calloc(10000, 1);
    while(1)
    {
        rd = read(fd, &output[counter], 1);
        if (rd <= 0)
            break;
        counter++;
    }
    output[counter + 1] = '\0';
    return(output);
}

char **split_input(char *input_str)
{
    char **output;
    output = ft_split(input_str, '\n');
    if(output == 0)
        return(NULL);
    return(output);
}

char    *remove_non_alnum(char *string, int i)
{
    while (string[i])
    {
        if (ft_isalnum(string[i]))
        {
            return(ft_strdup(&string[i]));
        }
        i++;
    }
    return (NULL);
}

void    init_elements(char **splitted, t_param *param)
{
    int i;
    t_cube *cube;

    i = 0;
    cube = param->cube;
    while (i < 6)
    {
        if (ft_strncmp(splitted[i], "NO ", 3) == 0)
            param->wall_path[NORTH_WALL] = remove_non_alnum(splitted[i], 3);
        else if (ft_strncmp(splitted[i], "SO ", 3) == 0)
            param->wall_path[SOUTH_WALL] = remove_non_alnum(splitted[i], 3);
        else if (ft_strncmp(splitted[i], "WE ", 3) == 0)
            param->wall_path[WEST_WALL] = remove_non_alnum(splitted[i], 3);
        else if (ft_strncmp(splitted[i], "EA ", 3) == 0)
            param->wall_path[EAST_WALL] = remove_non_alnum(splitted[i], 3);
        else if (ft_strncmp(splitted[i], "F ", 2) == 0)
            param->f = remove_non_alnum(splitted[i], 2);
        else if (ft_strncmp(splitted[i], "C ", 2) == 0)
            param->c = remove_non_alnum(splitted[i], 2);
        else
            init_elements_error(cube);
        i++;
    }
}

//This function takes our ".cub" map as an input
//Opens a file and copies the map with all symbols to char **map
//Returns Null (almost impossible) or a filled map
//Needs tests, also not sure is sets last map[i] to NULL
void    assign_map(char **splitted_input, t_cube *cube)
{
    int i;
    int j;

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

int find_longest_row(char **map)
{
    int i;
    int j;
    int longest;

    i = 0;
    j = 0;
    longest = j;
    while(map[i])
    {
        while(map[i][j])
        {
            j++;
            if(longest <= j)
            {
                longest = j;
            }
        }
        i++;
    }
    return(longest);
}

void allocate_map_with_spaces(t_param *param)
{
    int i;
    int j;
    int len;

    i = 0;
    j = array_size(param->map);
    param->longest_row_size = find_longest_row(param->map);
    param->new_map = malloc(sizeof(char *) * j + 1);
    param->new_map[j] = NULL;
    if(!param->new_map)
        free_all(param->cube);
    while(i < j)
    {
        param->new_map[i] = malloc(sizeof(char) * param->longest_row_size + 1);
        param->new_map[i][param->longest_row_size] = '\0';
        i++;
    }
    i = 0;
    while(i < j)
    {
        ft_strcpy(param->new_map[i], param->map[i]);
        len = ft_strlen(param->map[i]);
        while(len < param->longest_row_size)
        {
            param->new_map[i][len] = ' ';
            len++;
        }
        i++;
    }
    j = array_size(param->map);
    param->new_map[j - 1][param->longest_row_size - 1] = '\0';
}

void     parse_input(int argc, char *path, t_cube *cube)
{
    if (argc != 2)
        argc_error(cube);
    check_extension(path, cube);
    cube->param.input_str = read_from_file(path);
    cube->param.splitted_input = split_input(cube->param.input_str);
    init_elements(cube->param.splitted_input, &cube->param);
    // check_texture_files(&cube->param); // Comment out for debugging
    check_rgb(&cube->param);
    check_map_double_n(cube->param.input_str, cube);
    check_map_row(cube->param.splitted_input, cube);
    assign_map(cube->param.splitted_input, cube);
    allocate_map_with_spaces(&cube->param);
    check_invalid_spaces(cube->param.map, cube);
    check_player_wihtin_walls(cube->param.map, cube);
    // replace_spaces(cube->param.map);
    check_forbidden_chars(cube->param.map, cube);
    check_player(cube->param.map, cube);
}