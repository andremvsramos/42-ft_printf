NAME = libftprintf.a


CC = cc
FLAGS = -Wall -Wextra -Werror -I.

SRC = ft_bzero.c \
	ft_flagsprocess.c \
	ft_isdigit.c \
	ft_is_valid_flags.c \
	ft_memset.c \
	ft_printf.c \
	ft_printf2.c \
	ft_printf_checkdata.c \
	ft_printf_hexes.c \
	ft_printf_itoa.c \
	ft_printf_nums.c \
	ft_printf_utils.c \
	ft_strdup.c \
	ft_string_processing.c \
	ft_strlcpy.c \
	ft_strncmp.c \
	ft_char.c \
	ft_pflags.c \
	ft_hflags.c

OBJ = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
	@ar rcs ${NAME} ${OBJ}
	@ranlib ${NAME}

clean:
	@rm -rf ${OBJ}

bonus: all

fclean: clean
	@rm -rf ${NAME}

re: fclean all


