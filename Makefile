# Compilation
NAME = cub3D
CC = cc
CFLAGS = -Wextra -Wall -Werror -g
# DEBUG	= -fsanitize=address

## -Og -g3 -fsanitize=address

INC = -I $(INC_PATH)
MLX = -framework OpenGL -framework AppKit
## MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit
## FLAGS = -Wall -Wextra -Werror -Iincludes -g -Lmlx -lmlx -framework OpenGL -framework AppKit -o

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
SRC		=	main.c \
			$(addprefix parser/,\
			parser.c)

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
	@mkdir -p obj/parser
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
	@make clean -C $(MLX_F)

fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(LIB_F)
	
re: fclean all

.PHONY: all clean fclean re