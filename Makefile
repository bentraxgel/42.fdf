CC = cc
CFLAG = -Wall -Wextra -Werrer -Imlx
NAME = test
SRC = main.c
OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lminilibx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all : $(NAME)
clean : 
	rm -rf $(OBJS)
fclean : clean
	rm -rf $(NAME)
re : fclean all
.PHONY : all clean fclean re