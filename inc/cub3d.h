#ifndef CUB3D_H
# define CUB3D_H

/* Macros */
// Window Dimensions //
# define WIDTH 1024
# define HEIGHT 800
// Keys //
# define ESCAPE_KEY 53
# define KEY_DOWN 2
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define LEFT_KEY 123
# define RIGHT_KEY 124
// Movement //
# define MOVE_SPEED 0.15
# define ROTATION_SPEED 0.1
// MLX //
# define CLOSE_WINDOW 17
// Raycast //
# define FOV 90
# define RAY_COUNT WIDTH
# define CAMERA_PLANE 0.66
# define PITCH 100
# define TEXTURE_WIDTH 128
# define TEXTURE_HEIGHT 128
// Map //
# define NORTH_WALL 0
# define SOUTH_WALL 1
# define WEST_WALL 2
# define EAST_WALL 3
// Fd //
# define MAX_FD 1024
// Misc //
# define INT_MAX 2147483647

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
	char				*wall_path[4];
	char				*f;
	char				*c;
	int					*f_rgb;
	int					*c_rgb;
	char				**map;
	int					longest_row_size;
	char				**new_map;
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
}						t_img;

typedef struct s_wall
{
	t_img				*img;
	int					width;
	int					height;
}						t_wall;

typedef struct s_xy
{
	double				x;
	double				y;
}						t_xy;

typedef struct s_xy_int
{
	int					x;
	int					y;
}						t_xy_int;

typedef struct s_rc
{
	struct s_cube		*cube;
	t_xy				position;
	t_xy				direction;
	t_xy				camera_plane;
	double				camera_x;
	t_xy				ray_dir;
	t_xy_int			map;
	t_xy				side_dist;
	t_xy				delta_dist;
	t_xy				step;
	int					side;
	double				perp_wall_dist;
	int					line_height;
	int					draw_start;
	int					draw_end;
	int					pitch;
	t_wall				walls[4];
	int					wall_type;
	t_xy				texture;
	double				texture_step;
	double				texture_position;
	int					floor_color;
	int					ceiling_color;
	char				player_char;
}						t_rc;

typedef struct s_cube
{
	t_param				param;
	t_mlx				mlx;
	t_img				img;
	t_rc				rc;
}						t_cube;

/* Functions */
// Init Structs //
void			init_structs(t_cube *cube);

// Parsing //
void			parse_input(int argc, char *path, t_cube *cube);
int				check_extension(const char *file_name, t_cube *cube);
void			check_texture_files(t_param *param);
void			check_rgb(t_param *param);
void			check_map_double_n(char *input, t_cube *cube);
void			check_map_row(char **splitted_input, t_cube *cube);
void			check_invalid_spaces(char **map, t_cube *cube);
void			check_forbidden_chars(char **map, t_cube *cube);
void			check_player(char **map, t_cube *cube);
void			check_player_wihtin_walls(char **map, t_cube *cube);
void			replace_spaces(char **map);
void			allocate_map_with_spaces(t_param *param);
void			assign_map(char **splitted_input, t_cube *cube);

// Starting Values //
void			init_starting_values(t_cube *cube);

// Window //
void			launch_window(t_cube *cube);
void			load_textures(t_cube *cube);
void			render_window(t_cube *cube);

// Hooks //
int				key_hooks(int keycode, t_rc *rc);
int				x_close(void);
void			front_back_movement(t_rc *rc, char **map, int key);
void			left_right_movement(t_rc *rc, char **map, int key);
void			rotate_camera(t_rc *rc, int key);

// Raycasting //
void			raycasting(t_cube *cube);
void			draw_vertical_line(t_rc *rc, int x);

// Pixels and textures//
unsigned int	my_mlx_pixel_get(t_img *img, int x, int y);
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
void			load_textures(t_cube *cube);

// Utils //
char			*get_next_line(int fd);
int				array_size(char **arr);
int				rgb_to_hex(int *rgb);
void			print_double_array(char **arr);

// Error Handling //
void			argc_error(t_cube *cube);
void			extension_error(t_cube *cube);
void			init_elements_error(t_cube *cube);
void			file_error(t_cube *cube);
void			rgb_error(t_cube *cube);
void			error_double_n(t_cube *cube);
void			map_row_error(t_cube *cube);
void			invalid_spaces_error(t_cube *cube);
void			forbidden_chars_error(t_cube *cube);
void			player_error(t_cube *cube, char *msg);
void			texture_not_loaded_error(t_cube *cube);
void			out_of_bounds_error(t_cube *cube);
void			error_exit(char *message, t_cube *cube);

// Free Memory //
void			free_all(t_cube *cube);
void			free_double_str_ptr(char **arr);
void			free_str(char *str);
void			free_int_arr(int *arr);
void			free_double_str_ptr(char **arr);
void			free_img(t_img *img);

#endif