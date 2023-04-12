#ifndef CUB3D_H
# define CUB3D_H

/* Macros */


/* Libraries */
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
#include <fcntl.h>

# include "../mlx/mlx.h"
# include "../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

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
// Parser //
int		check_extension(const char *file_name);
char	**convert_map(char *file);

// Utils //
char	*read_file(int fd, char *stash);
char	*get_return(char *stash);
char	*get_next_line(int fd);
#endif