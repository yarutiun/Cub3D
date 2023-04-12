#include "cub3d.h"


//function checks that the map extension is ".cub"
//returns 1 if extension is not ".cub"
//returns 0 if test passed
int check_extension(const char *file_name)
{
    int len;

    len = ft_strlen(file_name);
    if(len > 4)
    {
        if(file_name[len-1] == 'b' && file_name[len - 2] == 'u' && \
        file_name[len - 3] == 'c' && file_name[len - 4] == '.')
            return(0);
        return(1);
    }
    return(1);
}

//This function takes our ".cub" map as an input
//Opens a file and copies the map with all symbols to char **map
//Returns Null (almost impossible) or a filled map
//Needs tests, also not sure is sets last map[i] to NULL
char **convert_map(char *file)
{
    char **map;
    int i;
    int fd;

    i = 0;
    fd = open(file, O_RDONLY);
    if(fd < 0)
        return(NULL);
    map = malloc(1000);
    map[i] = get_next_line(fd);
    while(map[i] != NULL)
    {
        i++;
        map[i] = get_next_line(fd);
    }
    return(map);
}

// int main(void)
// {
//     int count = 0;
//     char **map;
//     map = convert_map("/Users/yarutiun/Desktop/42_projects/Cub3D/maps/test.cub");
//     // printf("%s", map[0]);
//     while(map[count])
//     {
//         printf("%s", map[count]);
//         count++;
//     }
//     return(0);
// }