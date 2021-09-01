NAME 	=	mysh

INCS	= 	-I ./includes -I ./lib/my/includes

LIB	=	-L ./lib -lmy

SRCS	=	./sources/main.c \
		./sources/exec.c \
		./sources/parse.c \
		./sources/stack.c \
		./sources/utils/command.c \
		./sources/utils/env.c \
		./sources/utils/string.c \
		./sources/env/entry.c \
		./sources/env/verification.c \
		./sources/builtins.c

OBJS 	= 	$(SRCS:.c=.o)

CFLAGS	+= 	$(LIB) $(INCS) -W -Wall -Wextra

CC	= 	gcc

RM	= 	rm -f

all:		$(NAME)

$(NAME):	$(OBJS)
		make -C ./lib/my
		$(CC) -o $(NAME) $(OBJS) $(LIB) $(INCS)
clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
