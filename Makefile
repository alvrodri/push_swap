CHECKER_SRCS	=	srcs/checker.c \
					srcs/parser/parser.c srcs/parser/line_parser.c \
					srcs/util/print_instructions.c \
					srcs/util/print.c \
					srcs/instruction/push_instruction.c \
					srcs/instruction/swap_instruction.c \
					srcs/instruction/rotate_instruction.c \
					srcs/instruction/reverse_rotate_instruction.c \
					srcs/util/validation.c \
					srcs/util/utils.c

PUSH_SWAP_SRCS	=	srcs/push_swap.c \
					srcs/parser/parser.c \
					srcs/util/print_instructions.c \
					srcs/util/print.c \
					srcs/instruction/push_instruction.c \
					srcs/instruction/swap_instruction.c \
					srcs/instruction/rotate_instruction.c \
					srcs/instruction/reverse_rotate_instruction.c \
					srcs/util/validation.c \
					srcs/util/utils.c \
					srcs/sort/sort_small.c srcs/sort/sort_large.c \
					srcs/sort/aux/sort_large_aux1.c srcs/sort/aux/sort_large_aux2.c \
					srcs/sort/aux/sort_large_aux3.c

GNL				=	./resources/get_next_line/get_next_line.c \
					./resources/get_next_line/get_next_line_utils.c

CHECKER = checker
PUSH_SWAP = push_swap

CHECKER_OBJS = ${CHECKER_SRCS:.c=.o}
PUSH_SWAP_OBJS = ${PUSH_SWAP_SRCS:.c=.o}

CC = gcc
CFLAGS = #-Wall -Wextra -Werror

SANITIZE = -g3 -fsanitize=address

all:			${CHECKER} ${PUSH_SWAP}

${CHECKER}:		${CHECKER_OBJS}
				make bonus -C ./resources/libft/
				gcc ${GNL} ${CHECKER_OBJS} -L ./resources/libft/ -l ft -o ${CHECKER}

${PUSH_SWAP}:	${PUSH_SWAP_OBJS}
				make bonus -C ./resources/libft/
				gcc ${GNL} ${PUSH_SWAP_OBJS} -L ./resources/libft/ -l ft -o ${PUSH_SWAP}

clean:
			rm -f ${PUSH_SWAP_OBJS}
			rm -f ${CHECKER_OBJS}
			make clean -C ./resources/libft

fclean:		clean
			rm -f ${PUSH_SWAP}
			rm -f ${CHECKER}
			make fclean -C ./resources/libft

re:			fclean all

.PHONY:		all clean fclean re
