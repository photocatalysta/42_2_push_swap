/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 10:45:36 by jsala             #+#    #+#             */
/*   Updated: 2024/02/17 10:53:33 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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
	while (argv[++i])
	{
		temp_val = ft_atol(argv[i]);
		if (temp_val < INT_MIN || temp_val > INT_MAX)
			free_exit(&stack, NULL, 1);
		val = (int) temp_val;
		temp = ft_lstnew(val, 0);
		if (!temp)
			free_exit(&stack, NULL, 1);
		if (ft_lstval(stack, val))
			free_exit(&stack, NULL, 1);
		ft_lstadd_back(&stack, temp);
		if (pos)
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
			free_exit(&stack, NULL, 1);
	}
	stack = ft_init_args(stack, argv, pos);
	return (stack);
}

void	ft_push_swap(t_list **stack_a, t_list **stack_b)
{
	int	l_stack;

	l_stack = ft_lstsize(*stack_a);
	if (l_stack == 1 || is_ordered(*stack_a))
		return (free_exit(stack_a, stack_b, EXIT_SUCCESS));
	if (l_stack == 2)
	{
		write(1, "sa\n", 3);
		ft_swap(stack_a);
	}
	else if (l_stack == 3)
		ft_fast_sort_3(stack_a);
	else if (l_stack < 6)
		ft_fast_sort(stack_a, stack_b);
	else
		ft_stack_radixsort(stack_a, stack_b);
}
