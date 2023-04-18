#include "../../inc/cub3d.h"

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
void    check_files(t_param *param)
{
    int fd;

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
        if(ft_atoi(rgb_c[i]) <= 255 && ft_atoi(rgb_c[i]) >= 0 \
        && ft_atoi(rgb_f[i]) <= 255 && ft_atoi(rgb_f[i]) >= 0)
        {
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