/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:44:25 by jsala             #+#    #+#             */
/*   Updated: 2024/02/14 17:01:54 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_posmin(t_list *stackA)
{
	int	i;
	int	j;
	int	val;

	if (!stackA)
		return (-1);
	i = 0;
	j = 0;
	val = stackA->content;
	while (stackA)
	{
		if (stackA->content < val)
		{
			val = stackA->content;
			j = i;
		}
		stackA = stackA->next;
		i++;
	}
	return (j);
}

void	ft_swap_pos_1(t_list *stackA)
{
	write(1, "ra\n", 3);
	ft_rotate(&stackA);
	write(1, "sa\n", 3);
	ft_swap(&stackA);
}

void	ft_swap_pos_2(t_list *stackA)
{
	write(1, "rra\n", 4);
	ft_rotate_rev(&stackA);
	if (stackA->content < stackA->next->next->content)// (pos 1 > pos 3)
	{
		write(1, "sa\n", 4);
		ft_swap(&stackA);
	}
}

void	ft_swap_pos_3(t_list *stackA)
{
	if (stackA->content > stackA->next->content)// (pos 1 > pos 2)
	{
		write(1, "sa\n", 4);
		ft_swap(&stackA);
	}
	write(1, "ra\n", 3);
	ft_rotate(&stackA);
}

void	ft_fast_sort(t_list *stackA)
{
	int	pos;

	if (!stackA)
		free_exit(stackA, NULL, 1); // Shouldn't happen
	pos = ft_posmin(stackA);
	if (pos == -1)
		free_exit(stackA, NULL, 1);
	if (pos == 0)
		ft_swap_pos_1(stackA);
	else if (pos == 1)
		ft_swap_pos_2(stackA);
	else if (pos == 2)
		ft_swap_pos_3(stackA);
}
