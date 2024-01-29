SRCS = ft_ .c
SRCS_BONUS = ft_ .c

HEADERS = ft_push_swap.h
HEADERS_BONUS = ft_ .h

OBJS = ${SRCS:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}

DEPS = ${SRCS:.c=.d}

NAME = push_swap
FLAGS = -Wall -Wextra -Werror
REMOVE = rm -f

all : $(NAME)

$(NAME) : $(OBJS) Makefile

clean :
	$(REMOVE) $(OBJS) $(DEPS) $(OBJS_BONUS)

fclean : clean
	$(REMOVE) $(NAME) do_bonus

do_bonus : bonus

bonus : $(OBJS_BONUS)
	$(cc) $(FLAGS) -c $< -MMD -MP -o {$<:.c=.o}
	touch do_bonus

.PHONY: all bonus clean fclean re