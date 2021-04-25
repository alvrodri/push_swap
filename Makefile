CHECKER_SRCS	=	srcs/checker.c \
					srcs/parser.c srcs/line_parser.c \
					srcs/print.c \
					srcs/push_instruction.c \
					srcs/swap_instruction.c \
					srcs/rotate_instruction.c \
					srcs/reverse_rotate_instruction.c \
					srcs/validation.c \
					srcs/utils.c

PUSH_SWAP_SRCS	=	srcs/push_swap.c \
					srcs/parser.c \
					srcs/print.c \
					srcs/sort_three.c srcs/sort_five.c \
					srcs/push_instruction.c \
					srcs/swap_instruction.c \
					srcs/rotate_instruction.c \
					srcs/reverse_rotate_instruction.c \
					srcs/validation.c \
					srcs/utils.c

GNL				=	./get_next_line/get_next_line.c \
					./get_next_line/get_next_line_utils.c

CHECKER = checker
PUSH_SWAP = push_swap

CHECKER_OBJS = ${CHECKER_SRCS:.c=.o}
PUSH_SWAP_OBJS = ${PUSH_SWAP_SRCS:.c=.o}

CC = gcc
CFLAGS = #-Wall -Wextra -Werror

SANITIZE = -g3 -fsanitize=address

${CHECKER}:		${CHECKER_OBJS}
				make bonus -C ./libft/
				gcc ${GNL} ${SANITIZE} ${CHECKER_OBJS} -L ./libft/ -l ft -o ${CHECKER}

${PUSH_SWAP}:	${PUSH_SWAP_OBJS}
				make bonus -C ./libft/
				gcc ${GNL} ${SANITIZE} ${PUSH_SWAP_OBJS} -L ./libft/ -l ft -o ${PUSH_SWAP}

all:		${CHECKER} ${PUSH_SWAP}

clean:
			rm -f ${PUSH_SWAP_OBJS}
			rm -f ${CHECKER_OBJS}
			make clean -C ./libft

fclean:		clean
			rm -f ${PUSH_SWAP}
			rm -f ${CHECKER}
			make fclean -C ./libft

re:			fclean all

.PHONY:		all clean fclean re
