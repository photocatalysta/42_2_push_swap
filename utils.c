/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 22:23:42 by jsala             #+#    #+#             */
/*   Updated: 2024/02/16 18:39:31 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_lstmin(t_list *stack)
{
	int		val_min;
	t_list	*temp;

	temp = stack;
	val_min = temp->position;
	while (temp)
	{
		if (temp->position < val_min)
			val_min = temp->position;
		temp = temp->next;
	}
	return (val_min);
}
int	ft_lstmax(t_list *stack)
{
	int		val_max;
	t_list	*temp;

	temp = stack;
	val_max = 0;
	while (temp)
	{
		if (temp->position > val_max)
			val_max = temp->position;
		temp = temp->next;
	}
	return (val_max);
}

void	ft_clear(t_list **lst)
{
	t_list	*temp;

	while (*lst)
	{
		temp = *lst;
		*lst = (*lst)->next;
		free(temp);
	}
}

void	free_exit(t_list **stackA, t_list **stackB, int exit_val)
{
	if (exit_val == 1)
		write(2, "Error\n", 6);
	if (stackA && *stackA)
		ft_clear(stackA);
	if (stackB && *stackB)
		ft_clear(stackB);
	exit(exit_val);
}
