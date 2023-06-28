CC = cc
CFLAGS = -Wall -Wextra -Werror
ARFLAGS = rc
NAME = libft.a
INCD = libft.h $(GNL_DIR)get_next_line.h
MOD_DIR = module_my/
MOD_SRC = $(addprefix $(MOD_DIR), \
			my_atoi_pro.c\
			my_atoi_hex.c)
GNL_DIR = gnl/
GNL_SRC = $(addprefix $(GNL_DIR), \
			get_next_line.c get_next_line_utill.c)
SRCS = $(MOD_SRC) $(GNL_SRC) \
		ft_isalpha.c\
			ft_isdigit.c\
			ft_isalnum.c\
			ft_isascii.c\
			ft_isprint.c\
			ft_strlen.c\
			ft_memset.c\
			ft_bzero.c\
			ft_memcpy.c\
			ft_memmove.c\
			ft_strlcpy.c\
			ft_strlcat.c\
			ft_toupper.c\
			ft_tolower.c\
			ft_strchr.c\
			ft_strrchr.c\
			ft_strncmp.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_strnstr.c\
			ft_atoi.c\
			ft_calloc.c\
			ft_strdup.c\
			ft_substr.c\
			ft_strjoin.c\
			ft_strtrim.c\
			ft_split.c\
			ft_itoa.c\
			ft_strmapi.c\
			ft_striteri.c\
			ft_putchar_fd.c\
			ft_putstr_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c\
			ft_itoa_hex.c\
			ft_itoa_hex_long.c\
			ft_itoa_unsign.c\
			ft_strjoin_free.c\
			ft_lstnew.c\
			ft_lstadd_front.c\
			ft_lstsize.c\
			ft_lstlast.c\
			ft_lstadd_back.c\
			ft_lstdelone.c\
			ft_lstclear.c\
			ft_lstiter.c\
			ft_lstmap.c\
			ft_abs.c

OBJS = $(SRCS:.c=.o)
$(NAME) : $(OBJS)
	ar $(ARFLAGS) $(NAME) $(OBJS)

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean 
	make all
.PHONY : clean fclean all re