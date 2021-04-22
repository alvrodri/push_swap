CHECKER_SRCS = ./srcs/checker.c \
			   ./srcs/parser.c \
			   ./srcs/print.c \
			   ./srcs/swap_instruction.c ./srcs/push_instruction.c \
			   ./srcs/rotate_instruction.c ./srcs/reverse_rotate_instruction.c

PUSH_SWAP_SRCS =

CC = gcc
CFLAGS = -Wall -Wextra -Werror

CHECKER_OBJS = ${CHECKER_SRCS:.c=.o}
PUSH_SWAP_OBJS = $(PUSH_SWAP_SRCS:.c=.o)

LIBFT = -L ./libft/ -l ft

all:	checker push_swap

checker:	${CHECKER_OBJS}
	make -C ./libft/
	$(CC) $(CFLAGS) $(LIBFT) $(CHECKER_OBJS) -o checker

push_swap:
	make -C ./libft/
	$(CC) $(CFLAGS) $(LIBFT) $(PUSH_SWAP_OBJS) -o push_swap

clean:
	rm -rf $(CHECKER_OBJS) $(PUSH_SWAP_OBJS)
	make clean -C ./libft/

fclean:
	$(clean)
	rm -rf checker
	rm -rf push_swap
	make fclean -C ./libft/

re:	fclean all

.PHONY:	all checker push_swap clean fclean re
