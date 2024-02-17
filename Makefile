SRC_MAIN = main.c
SRCS = rotate.c swap.c push.c utils.c utils2.c fast_sort.c math.c moves.c init.c
SRCS_BONUS = checker/checker.c checker/rotate_check.c checker/swap_check.c checker/push_check.c
SRCS_TEST = test_utils.c

HEADERS = ft_push_swap.h

LIBFT = libft/libft.a
LIBFT_DIR = libft

OBJ_MAIN = ${SRC_MAIN:.c=.o}
OBJS = ${SRCS:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}
OBJS_TEST = ${SRCS_TEST:.c=.o}

DEPS = ${SRCS:.c=.d}
DEP_MAIN = ${SRC_MAIN:.c=.d}
DEPS_BONUS = ${SRCS_BONUS:.c=.d}
DEPS_TEST = ${SRCS_TEST:.c=.d}

MAKEFILE = Makefile

NAME = push_swap
CHECKER = checker

CC = gcc
FLAGS = -Wall -Wextra -Werror -MMD
REMOVE = rm -f

all : $(LIBFT) $(NAME)

-include $(DEPS)

%.o : %.c $(MAKEFILE)
	$(CC) $(FLAGS) -c $< -o ${<:.c=.o}

$(NAME) : $(OBJS) $(OBJ_MAIN)
	$(CC) $(FLAGS) $(LIBFT) $(OBJS) $(OBJ_MAIN) -o $(NAME)

$(LIBFT) :
	make bonus -C $(LIBFT_DIR)

clean :
	make clean -C $(LIBFT_DIR)
	$(REMOVE) $(OBJS) $(OBJ_MAIN) $(OBJS_BONUS) $(DEPS) $(DEP_MAIN) $(DEPS_BONUS)

fclean : clean
	make fclean -C $(LIBFT_DIR)
	$(REMOVE) $(NAME) $(CHECKER)

test : $(LIBFT) $(OBJS) $(OBJ_MAIN) $(OBJS_TEST)
	$(CC) -g $(FLAGS) $(LIBFT) $(OBJS) $(OBJ_MAIN) $(OBJS_TEST) -o $(NAME)

$(CHECKER) : bonus

bonus : $(LIBFT) $(OBJS_BONUS) $(OBJS)
	$(CC) $(FLAGS) $(LIBFT) $(OBJS) $(OBJS_BONUS) -o $(NAME)

.PHONY: all bonus clean fclean re
