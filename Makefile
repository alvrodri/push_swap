SRCS	=	srcs/checker.c \
			srcs/parser.c srcs/line_parser.c \
			srcs/print.c \
			srcs/push_instruction.c \
			srcs/swap_instruction.c \
			srcs/rotate_instruction.c \
			srcs/reverse_rotate_instruction.c \
			srcs/validation.c
GNL		=	./get_next_line/get_next_line.c \
			./get_next_line/get_next_line_utils.c

NAME = checker

OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = #-Wall -Wextra -Werror

SANITIZE = -g3 -fsanitize=address

${NAME}:	${OBJS}
			make bonus -C ./libft/
			gcc ${GNL} ${OBJS} -L ./libft/ -l ft -o ${NAME}
all:		${NAME}
clean:
			rm -f ${OBJS}
			make clean -C ./libft
fclean:		clean
			rm -f ${NAME}
			make fclean -C ./libft
re:			fclean all
.PHONY:		all clean fclean re
