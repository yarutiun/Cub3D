#ifndef CUB3D_H
# define CUB3D_H

/* Macros */


/* Libraries */
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>

# include "../mlx/mlx.h"
# include "../libft/libft.h"

/* Structs */
typedef struct s_param
{
	struct s_cube		*cube;
	char 				*input_str;
    char 				**splitted_input;
	char				*path;
	char				*no;
	char				*so;
	char				*we;
	char				*ea;
	char				*f;
	char				*c;
	char 				**map;
}						t_param;

typedef struct s_cube
{
	t_param				param;
}						t_cube;

/* Functions */
// Init Structs //
void	init_cube(t_cube *cube);
void	init_param(t_cube *cube);

// Parser //
void	parse_input(int argc, char *path, t_param *param);

// Utils //
char	*get_next_line(int fd);

// Errors //
void    argc_error(t_cube *cube);
void	extension_error(t_cube *cube);
void    init_elements_error(t_cube *cube);
void    file_error(t_cube *cube);
void    rgb_error(t_cube *cube);

// Free //
void	free_all(t_cube *cube);

#endif