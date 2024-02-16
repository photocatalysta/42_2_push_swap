/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fast_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:44:25 by jsala             #+#    #+#             */
/*   Updated: 2024/02/16 18:46:26 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_posmax(t_list *stackA)
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
		if (stackA->content > val)
		{
			val = stackA->content;
			j = i;
		}
		stackA = stackA->next;
		i++;
	}
	return (j);
}

void	ft_fast_sort_3(t_list **stackA)
{
	int		pos;
	t_list	*last;

	if (!stackA)
		free_exit(stackA, NULL, 1);
	pos = ft_posmax(*stackA);
	last = ft_lstlast(*stackA);
	if (((*stackA)->content > (*stackA)->next->content)
		&& ((*stackA)->content > last->content))
	{
		write(1, "ra\n", 3);
		ft_rotate(stackA);
	}
	else if (((*stackA)->content < (*stackA)->next->content)
		&& ((*stackA)->next->content > last->content))
	{
		write(1, "rra\n", 4);
		ft_rotate_rev(stackA);
	}
	if ((*stackA)->content > (*stackA)->next->content)
	{
		write(1, "sa\n", 3);
		ft_swap(stackA);
	}
}

void	ft_fix_order(t_list **stackA)
{
	while (!is_ordered(*stackA))
	{
		if ((*stackA)->position == 1)
		{
			write(1, "rra\n", 4);
			ft_rotate_rev(stackA);
			return ;
		}
		write(1, "ra\n", 3);
		ft_rotate(stackA);
	}
}

void	ft_fast_sort(t_list **stackA, t_list **stackB)
{
	int		l_list;

	l_list = ft_lstsize(*stackA);
	ft_push(stackA, stackB, 'b');
	if (l_list == 5)
		ft_push(stackA, stackB, 'b');
	if (!is_ordered(*stackA))
		ft_fast_sort_3(stackA);
	while (*stackB)
	{
		if (((*stackA)->position > (*stackB)->position
			&& ((ft_lstlast(*stackA))->position) < (*stackB)->position)
			|| ((*stackB)->position < ft_lstmin(*stackA) && (*stackA)->position == ft_lstmin(*stackA))
			|| ((*stackB)->position > ft_lstmax(*stackA) && (ft_lstlast(*stackA))->position == ft_lstmax(*stackA)))
			ft_push(stackB, stackA, 'a');
		else
		{
			write(1, "ra\n", 3);
			ft_rotate(stackA);
		}
	}
	ft_fix_order(stackA);
//	print_list(*stackA, 10);
}
