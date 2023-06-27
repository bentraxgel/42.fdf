CC = cc
CFLAGS = -Wall -Wextra -Werror
ARFLAGS = rc
NAME = gnl.a
INCD = gnl.h
SRCS = gnl.c gnlutill.c
OBJS = $(SRCS:.c=.o)
$(NAME) : $(NAME)($(OBJS))

all : $(NAME)

clean :
	rm -rf $(OBJS) $(OBJS_BNS)

fclean : clean
	rm -rf $(NAME) $(OBJS_BNS)

re : fclean all

.PHONY : clean fclean all re
