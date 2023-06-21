CC = cc
CFLAG = -Wall -Wextra -Werror -Imlx -g3 -fsanitize=address
NAME = test
SRC = main.c make_line.c my_mlx.c
OBJ = $(SRC:%.c=%.o)
OBJ_DIR = obj
OBJ_FILE = $(addprefix $(OBJ_DIR)/, $(OBJ))
LIB_DIR = ./libft

$(NAME): $(OBJ_FILE)
	make -C $(LIB_DIR) re
	$(CC) $(CFLAG) -L $(LIB_DIR) -l ft -Lminilibx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJ_FILE) -g
$(OBJ_DIR) : 
	mkdir -p $(OBJ_DIR)
$(OBJ_DIR)/%.o : %.c | $(OBJ_DIR)
	$(CC) $(CFLAG) -c $< -o $@

all : $(NAME)
clean : 
	 make -C $(LIB_DIR) clean
	rm -rf $(OBJ_DIR)
fclean : clean
	make -C $(LIB_DIR) fclean
	rm -rf $(NAME)
re : fclean all
.PHONY : all clean fclean re
