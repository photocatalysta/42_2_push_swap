/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fast_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:44:25 by jsala             #+#    #+#             */
/*   Updated: 2024/02/17 10:52:16 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_posmax(t_list *stack_a)
{
	int	i;
	int	j;
	int	val;

	if (!stack_a)
		return (-1);
	i = 0;
	j = 0;
	val = stack_a->content;
	while (stack_a)
	{
		if (stack_a->content > val)
		{
			val = stack_a->content;
			j = i;
		}
		stack_a = stack_a->next;
		i++;
	}
	return (j);
}

void	ft_fast_sort_3(t_list **stack_a)
{
	int		pos;
	t_list	*last;

	if (!stack_a)
		free_exit(stack_a, NULL, 1);
	pos = ft_posmax(*stack_a);
	last = ft_lstlast(*stack_a);
	if (((*stack_a)->content > (*stack_a)->next->content)
		&& ((*stack_a)->content > last->content))
	{
		write(1, "ra\n", 3);
		ft_rotate(stack_a);
	}
	else if (((*stack_a)->content < (*stack_a)->next->content)
		&& ((*stack_a)->next->content > last->content))
	{
		write(1, "rra\n", 4);
		ft_rotate_rev(stack_a);
	}
	if ((*stack_a)->content > (*stack_a)->next->content)
	{
		write(1, "sa\n", 3);
		ft_swap(stack_a);
	}
}

void	ft_fix_order(t_list **stack_a)
{
	while (!is_ordered(*stack_a))
	{
		if ((*stack_a)->position == 1)
		{
			write(1, "rra\n", 4);
			ft_rotate_rev(stack_a);
			return ;
		}
		write(1, "ra\n", 3);
		ft_rotate(stack_a);
	}
}

void	ft_fast_sort(t_list **stack_a, t_list **stack_b)
{
	int		l_list;

	l_list = ft_lstsize(*stack_a);
	ft_push(stack_a, stack_b, 'b');
	if (l_list == 5)
		ft_push(stack_a, stack_b, 'b');
	if (!is_ordered(*stack_a))
		ft_fast_sort_3(stack_a);
	while (*stack_b)
	{
		if (((*stack_a)->position > (*stack_b)->position
				&& ((ft_lstlast(*stack_a))->position) < (*stack_b)->position)
			|| ((*stack_b)->position < ft_lstmin(*stack_a)
				&& (*stack_a)->position == ft_lstmin(*stack_a))
			|| ((*stack_b)->position > ft_lstmax(*stack_a)
				&& (ft_lstlast(*stack_a))->position == ft_lstmax(*stack_a)))
			ft_push(stack_b, stack_a, 'a');
		else
		{
			write(1, "ra\n", 3);
			ft_rotate(stack_a);
		}
	}
	ft_fix_order(stack_a);
}
