/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 22:13:01 by jsala             #+#    #+#             */
/*   Updated: 2024/02/16 14:02:54 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdio.h>

int	*ft_sort_int(int *arr, int size)
{
	int	i;
	int	temp;

	i = 0;
	while (++i < size)
	{
		if (arr[i] < arr[i - 1])
		{
			temp = arr[i];
			arr[i] = arr[i - 1];
			arr[i - 1] = temp;
			i = 0;
		}
	}
	return (arr);
}

t_list	*ft_init_args(t_list *stack, char **argv, int **pos)
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
		temp = ft_lstnew(val, 0);
		if (!temp)
			free_exit(stack, NULL, 1);
		if (ft_lstval(stack, val))
			free_exit(stack, NULL, 1);
		ft_lstadd_back(&stack, temp); // Fix list to check for nulls
		(*pos)[i - 1] = val;
	}
	return (stack);
}

t_list	*ft_init_list(int argc, char **argv, t_list *stack, int **pos)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (argv[i][0] == '\0' || !ft_chknum(argv[i]))
			free_exit(stack, NULL, 1);
	}
	stack = ft_init_args(stack, argv, pos);
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
	if (l_stack == 2)
	{
		write(1, "sa\n", 3);
		ft_swap(&stackA);
	}
	else if (l_stack == 3)
		ft_fast_sort(&stackA);
	else
		ft_stack_radixsort(&stackA, &stackB);
}

int main(int argc, char **argv)
{
	t_list	*stackA;
	t_list	*stackB;
	int		*arr;

	if (argc < 2)
		return (0);
	arr = ft_calloc(argc - 1, sizeof(int));
	if (!arr)
		return (1);
	stackA = NULL;
	stackA = ft_init_list(argc, argv, stackA, &arr);
	arr = ft_sort_int(arr, argc - 1);
	stackA = ft_init_pos(stackA, arr, argc);
	free(arr);
	// init stackB here for convenience;
	stackB = NULL;
	ft_push_swap(stackA, stackB);
	free_exit(stackA, stackB, 0);
	return (0);
}
