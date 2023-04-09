NAME = cub3D

SRC = src/main.c 

FLAGS = -Wall -Wextra -Werror -Iincludes -g -Lmlx -lmlx -framework OpenGL -framework AppKit -o

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME):
	@$(MAKE) -C mlx/
	@$(CC) $(SRC) $(FLAGS) $(NAME)
	@echo "Everything compiled successfully"

clean:
	@$(RM) so_long
	
fclean: clean
	@$(MAKE) clean -C mlx/
	
re: fclean all
# -Og -g3 -fsanitize=address