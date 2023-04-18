#include "cub3d.h"

//This function takes our ".cub" map as an input
//Opens a file and copies the map with all symbols to char **map
//Returns Null (almost impossible) or a filled map
//Needs tests, also not sure is sets last map[i] to NULL
// char **convert_map(char *file)
// {
//     char **map;
//     int i;
//     int fd;

//     i = 0;
//     fd = open(file, O_RDONLY);
//     if(fd < 0)
//     {
//         map_err();
//         return(NULL);
//     }
//     map = malloc(1000);
//     map[i] = get_next_line(fd);
//     while(map[i] != NULL)
//     {
//         i++;
//         map[i] = get_next_line(fd);
//     }
//     return(map);
// }

//Returns 1 if any other characters detected in map but 01NSEW
//Retunrs 0 if check went successful
// int check_forbidden_chars(char **map)
// {
//     int i;
//     int j;
//     char *symbols;
//     symbols = "01NSEW";

//     i = 0;
//     while(map[i])
//     {
//         j = 0;
//         while(map[i][j])
//         {
//             if(!ft_strchr(symbols, map[i][j]))
//             {
//                 forbidden_chars_err();
//                 return(1);
//             }
//             j++;
//         }
//         i++;
//     }
//     return(0);
// }

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
    output = malloc(10000);
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

void    init_elements(char **splitted, t_param *param)
{
    int i;
    t_cube *cube;

    i = 0;
    cube = param->cube;
    while (i < 6)
    {
        if (ft_strncmp(splitted[i], "NO ", 3) == 0)
            param->no = ft_strdup(&splitted[i][3]);
        else if (ft_strncmp(splitted[i], "SO ", 3) == 0)
            param->so = ft_strdup(&splitted[i][3]);
        else if (ft_strncmp(splitted[i], "WE ", 3) == 0)
            param->we = ft_strdup(&splitted[i][3]);
        else if (ft_strncmp(splitted[i], "EA ", 3) == 0)
            param->ea = ft_strdup(&splitted[i][3]);
        else if (ft_strncmp(splitted[i], "F ", 2) == 0)
            param->f = ft_strdup(&splitted[i][2]);
        else if (ft_strncmp(splitted[i], "C ", 2) == 0)
            param->c = ft_strdup(&splitted[i][2]);
        else
            init_elements_error(cube);
        i++;
    }
}

void     parse_input(int argc, char *path, t_cube *cube)
{
    if (argc != 2)
        argc_error(cube);
    // int i = 0;
    // printf("%s", cube->param.input_str);
    check_extension(path, cube);
    cube->param.input_str = read_from_file(path);
    cube->param.splitted_input = split_input(cube->param.input_str);
    init_elements(cube->param.splitted_input, &cube->param);
    check_rgb(&cube->param);
    check_map_double_n(cube->param.input_str, cube);
    // while(cube->param.splitted_input[i])
    // {
    //     printf("%s\n", cube->param.splitted_input[i]);
    //     i++;
    // }
}