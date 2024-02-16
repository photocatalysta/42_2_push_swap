/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 09:51:27 by jsala             #+#    #+#             */
/*   Updated: 2024/02/16 15:05:38 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdio.h>

int	ft_max_pow_3(t_list *stackA)
{
	t_list	*temp;
	int		n_max;
	int		pos_max;
	int		pos;

	pos_max = 0;
	n_max = 0;
	temp = stackA;
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

void	ft_push_a(t_list **stackA, t_list **stackB, int digit)
{
	int	l_stackA;
	int	i;

	i = -1;
	l_stackA = ft_lstsize(*stackA);
	while (++i < l_stackA)
	{
		if (((*stackA)->position / ft_pow(3, digit)) % 3 == 1)
		{
			write(1, "ra\n", 3);
			ft_rotate(stackA);
			continue ;
		}
		ft_push(stackA, stackB, 'b');
		if (((*stackB)->position / ft_pow(3, digit)) % 3 == 2)
		{
			if (ft_lstsize(*stackB) > 1)
			{
				write(1, "rb\n", 3);
				ft_rotate(stackB);
			}
		}
	}
}

void	ft_push_b(t_list **stackA, t_list **stackB, int digit)
{
	int	l_stackB;
	int	i;

	i = -1;
	l_stackB = ft_lstsize(*stackB);
	while (++i < l_stackB)
	{
		ft_push(stackB, stackA, 'a');
		if (((*stackA)->position / ft_pow(3, digit)) % 3 == 2)
		{
			write(1, "ra\n", 3);
			ft_rotate(stackA);
		}
	}
}

void	ft_stack_radixsort(t_list **stackA, t_list **stackB)
{
	int digit;
	int	i;

	digit = ft_max_pow_3(*stackA);
//	printf("Digit: %i", digit);
	i = 0;
	while (i < digit)
	{
		ft_push_a(stackA, stackB, i);
		ft_push_b(stackA, stackB, i);
		i++;
	}
//	print_list(*stackA, 10);
//	print_list(*stackB, 10);
}
