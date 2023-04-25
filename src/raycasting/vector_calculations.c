#include "cub3d.h"

double	pythagoras(t_xy coord)
{
	return(sqrt((coord.x * coord.x) + (coord.y * coord.y)));
}

t_xy	add_vector(t_xy v1, t_xy v2)
{
	t_xy	result;

	result.x = v1.x + v2.x;
	result.y = v2.y + v2.y;
	return (result);
}

t_xy	sub_vector(t_xy v1, t_xy v2)
{
	t_xy	result;

	result.x = v1.x - v2.x;
	result.y = v2.y - v2.y;
	return (result);
}

t_xy	normalize_vector(t_xy vector)
{
	t_xy	result;
	double	length;
	
	length = sqrt(vector.x * vector.x + vector.y * vector.y);
	result.x = vector.x / length;
	result.y = vector.y / length;
	return (result);
}
