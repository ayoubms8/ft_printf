SRCS = ft_printf.c utils.c

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

MAKE = make

%o:%c ft_printf.h
	gcc -Wall -Wextra -Werror -c $< -o $@

${NAME}: ${OBJS}
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}

all: ${NAME}

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY:all fclean clean re