CC = gcc
CFLAGS = -Wall -Werror -Wextra

RM		= rm -f

NAME	= ft_cat

SRCS	= ft_cat.c ft_open_file.c ft.c

OBJS	= ${SRCS:.c=.o}

all:		$(NAME)

${NAME}:	${OBJS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} $(NAME)

re:			fclean all