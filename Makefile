SERVER_OBJS		=       ${SERVER_SRCS:.c=.o}
CLIENT_OBJS		=		${CLIENT_SRCS:.c=.o}

SERVER_SRCS	=	srcs/server/server.c srcs/ft_util.c srcs/ft_util_2.c
CLIENT_SRCS =	srcs/client/client.c srcs/ft_util.c srcs/ft_util_2.c 

CC      =       clang

FLAGS   =       -Wall -Wextra -Werror

NAME    =       minitalk
SERVER	=		server
CLIENT	=		client

RM      =       rm -rf

all:    ${NAME}

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${SERVER} ${CLIENT}

${SERVER}:	  ${SERVER_OBJS}
			${CC} -o ${SERVER} ${SERVER_OBJS}

${CLIENT}:	  ${CLIENT_OBJS}
			${CC} -o ${CLIENT} ${CLIENT_OBJS}

clean:
	${RM} ${CLIENT_OBJS} ${SERVER_OBJS}

fclean:         clean
	${RM} ${SERVER} ${CLIENT}

re:	fclean all

.PHONY: all clean fclean re
