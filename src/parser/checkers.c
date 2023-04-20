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

// Needs testing
void    check_texture_files(t_param *param)
{
    int fd;

    fd = 0;
    fd = open(param->no, O_RDONLY);
    if(fd == -1)
        file_error(param->cube);
    fd = open(param->so, O_RDONLY);
    if(fd == -1)
        file_error(param->cube);
        fd = open(param->we, O_RDONLY);
    if(fd == -1)
        file_error(param->cube);
        fd = open(param->ea, O_RDONLY);
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

void    check_map_double_n(char *input, t_cube *cube)
{
    int count;
    int flag;

    count = 0;
    flag = 0;

    while(flag < 6)
    {
        if(ft_isalpha(input[count]))
        {
            while(input[count])
            {
                if(input[count] == '\n')
                {
                    flag++;
                    break;
                }
                count++;
            }
        }
        count++;
    }
    while(input[count])
    {
        if(input[count] == ' ' || input[count] == '1' || input[count] == '0')
            break;
        count++;
    }
    while(input[count])
    {
        if(input[count] == '\n' && input[count + 1] && input[count + 1] == '\n')
            error_double_n(cube);
        count++;
    }
}

void    check_map_row(char **splitted_input, t_cube *cube)
{
    int i;
    int last_i;

    i = 6;
    while (splitted_input[i])
    {
        last_i = ft_strlen(splitted_input[i]) - 1;

        if (splitted_input[i][last_i] == '0')
            map_row_error(cube);
        else if (splitted_input[i][0] == '0')
            map_row_error(cube);
        i++;
    }
}

void	check_invalid_spaces(char **map, t_cube *cube)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if(map[i][j] == '0')
            {
                if (map[i][j + 1] && map[i][j + 1] == ' ')
                    invalid_spaces_error(cube);
                if (map[i][j - 1] && map[i][j - 1] == ' ')
                    invalid_spaces_error(cube);
                if (map[i + 1][j] && map[i + 1][j] == ' ')
                    invalid_spaces_error(cube);
                if (map[i - 1][j] && map[i - 1][j] == ' ')
                    invalid_spaces_error(cube);
            }
            j++;
        }
        i++;
    }
}
