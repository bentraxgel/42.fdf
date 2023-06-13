CC = cc
CFLAG = -Wall -Wextra -Werror -Imlx
NAME = test
SRC = main.c
OBJ = $(SRC:%.c=%.o)
OBJ_DIR = obj
OBJ_FILE = $(addprefix $(OBJ_DIR)/, $(OBJ))

$(NAME): $(OBJ_FILE)
	$(CC) $(CFLAG) -Lminilibx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJ_FILE)
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