SRCS 		= pipex.c utils.c utils2.c ft_split.c

NAME		= pipex

HEADER		= pipex.h

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

${NAME}:
	${CC} ${CFLAGS} ${SRCS} -o ${NAME} -fsanitize=address

all: ${NAME}

clean:
	${RM} ${NAME}

fclean:
	${RM} ${NAME}

re:	fclean all

.PHONY: all, fclean, clean, re