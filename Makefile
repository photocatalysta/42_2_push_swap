SRCS = rotate.c swap.c push.c utils.c utils2.c test_utils.c fast_sort.c math.c moves.c moves_utils.c  main.c
SRCS_BONUS = ft_checker.c

HEADERS = ft_push_swap.h

LIBFT = libft/libft.a
LIBFT_DIR = libft

OBJS = ${SRCS:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}

DEPS = ${SRCS:.c=.d}

MAKEFILE = Makefile

NAME = push_swap

CC = gcc
FLAGS = -Wall -Wextra -Werror -MMD
REMOVE = rm -f

all : $(LIBFT) $(NAME)

-include $(DEPS)

%.o : %.c $(MAKEFILE)
	$(CC) $(FLAGS) -c $< -o ${<:.c=.o}

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(LIBFT) $(OBJS) -o $(NAME)

$(LIBFT) :
	make bonus -C $(LIBFT_DIR)

clean :
	make clean -C $(LIBFT_DIR)
	$(REMOVE) $(OBJS) $(DEPS) $(OBJS_BONUS)

fclean : clean
	make fclean -C $(LIBFT_DIR)
	$(REMOVE) $(NAME) do_bonus

test : $(LIBFT) $(OBJS)
	$(CC) -g $(FLAGS) $(LIBFT) $(OBJS) -o $(NAME)

do_bonus : bonus

bonus : $(OBJS_BONUS)
	$(CC) $(FLAGS) -c $< -MMD -o ${<:.c=.o}
	touch do_bonus

.PHONY: all bonus clean fclean re
