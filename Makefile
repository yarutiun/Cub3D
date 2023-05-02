# Compilation
NAME = cub3D
CC = cc
CFLAGS = -Wextra -Wall -Werror -g
DEBUG	= -fsanitize=address
INC = -I $(INC_PATH)
MLX = -framework OpenGL -framework AppKit

# Clean
RM = rm -rf

# Directories
SRC_PATH = src/
OBJ_PATH = obj/
INC_PATH = inc/

LIB_F = libft/
MLX_F = mlx/

LIB_A = libft.a
MLX_A = libmlx.a

# Source and object files
SRC		=	error_handling/errors.c \
			parsing/checker_utils.c \
			parsing/alloc_map_spaces.c \
			error_handling/errors_player_and_textures.c \
			error_handling/errors_map.c \
			free_memory/free_utils.c \
			free_memory/free_general.c \
			parsing/checkers.c \
			parsing/map_checkers.c \
			parsing/make_map_rectangular.c \
			parsing/parse_input.c \
			parsing/print_double_array.c \
			raycasting/init_starting_values.c \
			raycasting/draw_vertical_line.c \
			raycasting/raycasting.c \
			window/key_actions.c \
			window/key_hooks.c \
			window/launch_window.c \
			init_structs.c \
			main.c \
			utils.c

SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))

# Colors
GREEN	:= \x1b[32m
RESET	:= \033[0m

# Rules
all: $(NAME)

## Update folder names here ##
$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@mkdir -p	obj/error_handling \
				obj/free_memory \
				obj/parsing \
				obj/raycasting \
				obj/window
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)
	
$(NAME): $(OBJS)
	@make -C $(LIB_F)
	@make bonus -C $(LIB_F)
	@make -C $(MLX_F)
	@$(CC) $(CFLAGS) $(OBJS) $(LIB_F)$(LIB_A) $(MLX_F)$(MLX_A) $(MLX) $(DEBUG) -o $(NAME)
	@echo "\n$(GREEN)Everything compiled successfully$(RESET)"

clean:
	$(RM) $(OBJ_PATH)
	@make clean -C $(LIB_F)
	# @make clean -C $(MLX_F)

fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(LIB_F)
	
re: fclean all

.PHONY: all clean fclean re