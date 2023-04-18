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
	int					*f_rgb;
	int					*c_rgb;
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
void	parse_input(int argc, char *path, t_cube *cube);
int		check_extension(const char *file_name, t_cube *cube);
void	check_files(t_param *param);
void	check_rgb(t_param *param);
void	check_map_double_n(char *input, t_cube *cube);
void    check_map_row(char **splitted_input, t_cube *cube);
void	check_invalid_spaces(char **map, t_cube *cube);

// Utils //
char	*get_next_line(int fd);

// Errors //
void    argc_error(t_cube *cube);
void	extension_error(t_cube *cube);
void    init_elements_error(t_cube *cube);
void    file_error(t_cube *cube);
void    rgb_error(t_cube *cube);
void	error_double_n(t_cube *cube);
void    map_row_error(t_cube *cube);
void    invalid_spaces_error(t_cube *cube);
void	forbidden_chars_error(t_cube *cube);


// Free //
void	free_all(t_cube *cube);
void	free_double_str_ptr(char **arr);

#endif