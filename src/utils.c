#include "cub3d.h"

int     array_size(char **arr)
{
    int i;

    i = 0;
    while (arr[i])
    {
        i++;
    }
    return (i);
}
