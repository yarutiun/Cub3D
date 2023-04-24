#ifndef CUB3D_H
# define CUB3D_H

/* Macros */
// Window Dimensions //
# define WIDTH 1920
# define HEIGHT 1080

// Keys //
# define ESCAPE 17

// Raycast //
# define FOV 90
# define RAY_COUNT WIDTH

// Walls //
# define NORTH_WALL 0
# define SOUTH_WALL 1
# define WEST_WALL 2
# define EAST_WALL 3

// Fd //
# define MAX_FD 1024

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
	char				*input_str;
	char				**splitted_input;
	char				*no;
	char				*so;
	char				*we;
	char				*ea;
	char				*f;
	char				*c;
	int					*f_rgb;
	int					*c_rgb;
	char				**map;
}						t_param;

typedef struct s_mlx
{
	struct s_cube		*cube;
	void				*mlx_ptr;
	void				*window;

}						t_mlx;

typedef struct s_img
{
	struct s_cube		*cube;
	void				*img;
	char				*address;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
	void				*wall_ptr; // 2D
}						t_img;

typedef struct			s_xy
{
	double				x;
	double				y;
}						t_xy;

typedef struct s_ray
{
	struct s_cube		*cube;
	double				ray_angle_diff;
	double				distance;
	t_xy				direction;
	t_xy				tmp_direction;
	double				radiant_diff;
	int					current_wall;
	t_xy				intersection;
	t_xy				h_intersection;
	t_xy				v_intersection;



}						t_ray;

typedef struct s_cube
{
	t_param				param;
	t_mlx				mlx;
	t_img				img;
	t_ray				ray;
}						t_cube;

/* Functions */
// Init Structs //
void	init_structs(t_cube *cube);

// Parsing //
void	parse_input(int argc, char *path, t_cube *cube);
int		check_extension(const char *file_name, t_cube *cube);
void	check_texture_files(t_param *param);
void	check_rgb(t_param *param);
void	check_rgb_digits(t_cube *cube);
void	check_map_double_n(char *input, t_cube *cube);
void	check_map_row(char **splitted_input, t_cube *cube);
void	check_invalid_spaces(char **map, t_cube *cube);
void	check_forbidden_chars(char **map, t_cube *cube);
void	check_player(char **map, t_cube *cube);

// Window //
void	launch_window(t_cube *cube);
void	render_window(t_cube *cube);

// Hooks //
int		x_close(void);
int		key_hooks(int keycode);

// Raycasting //
void	raycasting(t_cube *cube);

// Utils //
char	*get_next_line(int fd);
int		array_size(char **arr);

// Error Handling //
void	argc_error(t_cube *cube);
void	extension_error(t_cube *cube);
void	init_elements_error(t_cube *cube);
void	file_error(t_cube *cube);
void	rgb_error(t_cube *cube);
void	error_double_n(t_cube *cube);
void	map_row_error(t_cube *cube);
void	invalid_spaces_error(t_cube *cube);
void	forbidden_chars_error(t_cube *cube);
void	player_error(t_cube *cube, char *msg);

// Free Memory //
void	free_all(t_cube *cube);
void	free_double_str_ptr(char **arr);

#endif