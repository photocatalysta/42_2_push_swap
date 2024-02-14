/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 22:13:01 by jsala             #+#    #+#             */
/*   Updated: 2024/02/14 15:10:32 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_list	*ft_init_args(t_list *stack, char **argv)
{
	int			i;
	long int	temp_val;
	int			val;
	t_list		*temp;

	i = 0;
	while (argv[++i]) // What happens if I pass a 0 value as one of the arguments?
	{
		temp_val = ft_atol(argv[i]);
		if (temp_val < INT_MIN || temp_val > INT_MAX)
			free_exit(stack, NULL, 1);
		val = (int) temp_val;
		if (i == 1)
		{
			stack->content = val;
			continue;
		}
		temp = ft_lstnew(val);
		if (!temp)
			free_exit(stack, NULL, 1);
		if (ft_lstval(stack, val))
			free_exit(stack, NULL, 1);
		ft_lstadd_back(&stack, temp); // Fix list to check for nulls
	}
	return (stack);
}

t_list	*ft_init_list(int argc, char **argv, t_list *stack)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (argv[i][0] == '\0' || !ft_chknum(argv[i]))
			free_exit(stack, NULL, 1);
	}
	stack = ft_init_args(stack, argv);
	// No res or free check needed, we can exit... // Need to check if arguments passed are wrong too
	return (stack);
}

void	ft_push_swap(t_list *stackA, t_list *stackB)
{
	int	l_stack;
	// do I need a temp or it is okay since the only modifiable content is
	// waht is internal to the array?

	l_stack = ft_lstsize(stackA);
	if (l_stack == 1 || is_ordered(stackA))
		return(free_exit(stackA, stackB, EXIT_SUCCESS));
	test_stack(stackA, stackB);
	/*
	if (l_stack < 6)
		fast_sort(stackA, stackB);
	else
		fast_sort(stackA, stackB);

	while (stackA)
	{
		stackA->pos = get_arr_pos(arr, , stackA->content);
		stackA = stackA->next;
	}*/
}

int main(int argc, char **argv)
{
	t_list	*stackA;
	t_list	*stackB;

	stackA = malloc(sizeof(t_list));
	if (!stackA)
		free_exit(stackA, NULL, 1);
	stackA = ft_init_list(argc, argv, stackA);
	// init stackB here for convenience;
	stackB = malloc(sizeof(t_list));
	if (!stackB)
		free_exit(stackA, stackB, 1);
	ft_push_swap(stackA, stackB);
	return (0);
}
