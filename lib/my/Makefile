SRC	=	sources/my_strlen.c \
		sources/my_strcpy.c \
		sources/my_strcat.c \
		sources/my_strcmp.c \
		sources/my_strncmp.c \
		sources/my_strdup.c \
		sources/my_str_to_arr.c \
		sources/my_get_nbr.c \
		sources/my_printf.c \
		sources/my_put_nbr.c \
		sources/my_putchar.c \
		sources/my_putstr.c \
		sources/my_putstr_oct.c

OBJS	=	$(SRC:.c=.o)

CC	=	gcc

INC	=	-I ./includes

CFLAGS	=	$(INC) -W -Wall -Wextra -Werror

NAME	=	libmy.a

all:		$(NAME)

$(NAME):	$(OBJS)
		ar rc -f $(NAME) $(OBJS)
		mv $(NAME) ../$(NAME)

clean:
		$(RM) -f $(OBJS)

fclean:		clean
		$(RM) -f $(NAME)

re:		fclean all
