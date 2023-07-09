CC = cc
# CFLAG = -Wall -Wextra -Werror -Imlx -g3 -fsanitize=address
CFLAG = -Wall -Wextra -Werror -Imlx
NAME = fdf
SRC = main.c make_line.c my_mlx.c parsing.c main_utill.c rotation_matrix.c \
		init.c map_vis.c hook.c map_move.c earth.c
OBJ = $(SRC:%.c=%.o)
OBJ_DIR = obj
OBJ_FILE = $(addprefix $(OBJ_DIR)/, $(OBJ))
LIB_DIR = ./libft
USE_LIB = 
MLXFLAG = -L ./minilibx -lmlx -framework OpenGL -framework Appkit

$(NAME): $(OBJ_FILE)
	make -C $(LIB_DIR)
	$(CC) $(CFLAG) -L $(LIB_DIR) -l ft $(MLXFLAG) -o $(NAME) $(OBJ_FILE) -g
$(OBJ_DIR) : 
	mkdir -p $(OBJ_DIR)
$(OBJ_DIR)/%.o : %.c | $(OBJ_DIR)
	$(CC) $(CFLAG) -c $< -o $@

all : $(NAME)
	clear make -C $(LIB_DIR) clean
clean : 
	rm -rf $(OBJ_DIR)
fclean : clean
	make -C $(LIB_DIR) fclean
	rm -rf $(NAME)
re : fclean
	make all
.PHONY : all clean fclean re
