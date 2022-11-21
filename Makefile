NAME = libftprintf.a

CC = cc
FLAGS = -Wall -Wextra -Werror -I.

SRC =

OBJ = ${SRC:.c=.o}

BONUS = 

BONUS_OBJ = ${BONUS:.c=.o}


all: ${NAME}

${NAME}: ${OBJ}
	@ar rcs ${NAME} ${OBJ}
	@ranlib ${NAME}

clean:
	@rm -rf ${OBJ}

fclean: clean
	@rm -rf ${NAME}

re: fclean all


