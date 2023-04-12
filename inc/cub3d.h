#ifndef CUB3D_H
# define CUB3D_H

/* Macros */


/* Libraries */
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

# include "../mlx/mlx.h"
# include "../libft/libft.h"

/* Structs */
typedef struct s_square
{
	struct s_cube		*cube;
	int					area;
}						t_square;

typedef struct s_cube
{
	t_square			*squares;
	int					volume;	
}						t_cube;

/* Functions */
// Parse Arguments //

// Utils //

#endif