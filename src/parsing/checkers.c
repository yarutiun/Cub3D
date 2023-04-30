#include "cub3d.h"

//function checks that the map extension is ".cub"
//returns 1 if extension is not ".cub"
//returns 0 if test passed
int check_extension(const char *file_name, t_cube *cube)
{
    int len;

    len = ft_strlen(file_name);
    if(len > 4)
    {
        if(file_name[len-1] == 'b' && file_name[len - 2] == 'u' && \
        file_name[len - 3] == 'c' && file_name[len - 4] == '.')
            return(0);
        extension_error(cube);
        return(1);
    }
    extension_error(cube);
    return(1);
}

void    check_texture_files(t_param *param)
{
    int fd;

    fd = 0;
    fd = open(param->wall_path[NORTH_WALL], O_RDONLY);
    if(fd == -1)
        file_error(param->cube);
    fd = open(param->wall_path[SOUTH_WALL], O_RDONLY);
    if(fd == -1)
        file_error(param->cube);
        fd = open(param->wall_path[WEST_WALL], O_RDONLY);
    if(fd == -1)
        file_error(param->cube);
        fd = open(param->wall_path[EAST_WALL], O_RDONLY);
    if(fd == -1)
        file_error(param->cube);
}

void    check_rgb(t_param *param)
{
    int     i;
    char    **rgb_f;
    char    **rgb_c;

    i = 0;
    rgb_c = ft_split(param->c, ',');
    rgb_f = ft_split(param->f, ',');
    while (rgb_c[i] && rgb_f[i])
    {
        i++;
    }
    if (i != 3)
    {
        free_double_str_ptr(rgb_c);
        free_double_str_ptr(rgb_f);
        rgb_error(param->cube);
    }

    i = 0;
    while (rgb_c[i] && rgb_f[i])
    {
        if(ft_atoi(rgb_c[i]) <= 255 && ft_atoi(rgb_c[i]) >= 0 \
        && ft_atoi(rgb_f[i]) <= 255 && ft_atoi(rgb_f[i]) >= 0)
        {
            if (ft_atoi(rgb_c[i]) == -1 || ft_atoi(rgb_f[i]) == -1)
            {
                free_double_str_ptr(rgb_c);
                free_double_str_ptr(rgb_f);
                rgb_error(param->cube);
            }
            param->f_rgb[i] = ft_atoi(rgb_f[i]);
            param->c_rgb[i] = ft_atoi(rgb_c[i]);
            i++;
        }
        else
        {
            free_double_str_ptr(rgb_c);
            free_double_str_ptr(rgb_f);
            rgb_error(param->cube);    
        }
    }
    free_double_str_ptr(rgb_c);
    free_double_str_ptr(rgb_f);
}

void	check_player_wihtin_walls(char **map, t_cube *cube)
{
    int i;
    int j;

    i = 0;
    while (i < array_size(map))
    {
        j = 0;
        while (j < (int)ft_strlen(map[i]))
        {
            if(map[i][j] == 'N' || map[i][j] == 'E' || map[i][j] == 'W' || map[i][j] == 'S')
            {
                if (map[i][j + 1] && map[i][j + 1] == ' ')
                    out_of_bounds_error(cube);
                if (map[i][j - 1] && map[i][j - 1] == ' ')
                    out_of_bounds_error(cube);
                if (map[i + 1][j] && map[i + 1][j] == ' ')
                    out_of_bounds_error(cube);
                if (map[i - 1][j] && map[i - 1][j] == ' ')
                    out_of_bounds_error(cube);
            }
            j++;
        }
        i++;
    }
}

void    check_player(char **map, t_cube *cube)
{
    int i;
    int j;
    int flag;
    char *symbols;

    symbols = "NSEW";
    flag = 0;
    i = 0;
    while(i < array_size(map))
    {
        j = 0;
        while(j < (int)ft_strlen(map[i]))
        {
            if(ft_strchr(symbols, map[i][j]))
            {
                cube->rc.position.x = i;
                cube->rc.position.y = j;
                cube->rc.player_char = map[i][j];
                flag++;
            }
            j++;
        }
        i++;
    }
    if(flag == 0)
        player_error(cube, "No players on the map\n");
    else if(flag > 1)
        player_error(cube, "Too many players on the map\n");
}
