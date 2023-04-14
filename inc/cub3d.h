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
	char				**file_input;
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
	t_param				*param;
}						t_cube;

/* Functions */
// Parser //
int		parser(void);
int		check_extension(const char *file_name);
char	**convert_map(char *file);

// Utils //
char	*read_file(int fd, char *stash);
char	*get_return(char *stash);
char	*get_next_line(int fd);

// Errors //
int		parsing_err(void);

#endif