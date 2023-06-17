CC = cc
CFLAG = -Wall -Wextra -Werror -Imlx -g3 -fsanitize=address
NAME = fdf
SRC = main.c make_line.c my_mlx.c
OBJ = $(SRC:%.c=%.o)
OBJ_DIR = obj
OBJ_FILE = $(addprefix $(OBJ_DIR)/, $(OBJ))
LIB_DIR = ./libft/
GNL_DIR = ./gnl/

$(NAME): $(OBJ_FILE)
	make -C $(LIB_DIR) all
	make -C $(GNL_DIR) all
	$(CC) $(CFLAG) -Lminilibx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJ_FILE) -g
$(OBJ_DIR) : 
	mkdir -p $(OBJ_DIR)
$(OBJ_DIR)/%.o : %.c | $(OBJ_DIR)
	$(CC) $(CFLAG) -c $< -o $@

all : $(NAME)
clean : 
	rm -rf $(OBJ_DIR)
fclean : clean
	rm -rf $(NAME)
re : fclean all
.PHONY : all clean fclean re