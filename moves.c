/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 09:51:27 by jsala             #+#    #+#             */
/*   Updated: 2024/03/11 09:18:16 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_max_pow_3(t_list *stack_a)
{
	t_list	*temp;
	int		n_max;
	int		pos_max;
	int		pos;

	pos_max = 0;
	n_max = 0;
	temp = stack_a;
	while (temp)
	{
		pos = temp->position;
		if (pos > pos_max)
			pos_max = pos;
		temp = temp->next;
	}
	while (pos_max != 0)
	{
		n_max++;
		pos_max /= 3;
	}
	return (n_max);
}

void	ft_push_a(t_list **stack_a, t_list **stack_b, int digit)
{
	int	l_stack_a;
	int	i;

	i = -1;
	l_stack_a = ft_lstsize(*stack_a);
	while (++i < l_stack_a)
	{
		if (((*stack_a)->position / ft_pow(3, digit)) % 3 == 1)
		{
			write(1, "ra\n", 3);
			ft_rotate(stack_a);
			continue ;
		}
		ft_push(stack_a, stack_b, 'b');
		if (((*stack_b)->position / ft_pow(3, digit)) % 3 == 2)
		{
			if (ft_lstsize(*stack_b) > 1)
			{
				write(1, "rb\n", 3);
				ft_rotate(stack_b);
			}
		}
	}
}

void	ft_push_b(t_list **stack_a, t_list **stack_b, int digit)
{
	int	l_stack_b;
	int	i;

	i = -1;
	l_stack_b = ft_lstsize(*stack_b);
	while (++i < l_stack_b)
	{
		ft_push(stack_b, stack_a, 'a');
		if (((*stack_a)->position / ft_pow(3, digit)) % 3 == 2)
		{
			write(1, "ra\n", 3);
			ft_rotate(stack_a);
		}
	}
}

void	ft_stack_radixsort(t_list **stack_a, t_list **stack_b)
{
	int	digit;
	int	i;

	digit = ft_max_pow_3(*stack_a);
	i = 0;
	while (i < digit)
	{
		ft_push_a(stack_a, stack_b, i);
		ft_push_b(stack_a, stack_b, i);
		i++;
	}
}
