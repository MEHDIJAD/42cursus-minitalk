SRCS = ft_printf.c ft_print_format.c ft_printchar.c ft_printstr.c ft_printdigit.c 

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a
LIBC = ar rcs
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)

%.o:%.c ft_printf.h
	${CC} ${CFLAGS} -c $< -o $@
	${LIBC} ${NAME} $@

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: clean
