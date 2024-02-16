/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 22:23:42 by jsala             #+#    #+#             */
/*   Updated: 2024/02/16 16:20:03 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdio.h>

t_list	*ft_init_pos(t_list *stackA, int *arr, int argc)
{
	int		i;
	int		val;
	t_list	*temp;

	i = 0;
	temp = stackA;
	while (temp)
	{
		val = temp->content;
		while (i < argc && val != arr[i])
			i++;
		if (val == arr[i])
		{
			temp->position = i;
			i = 0;
		}
		temp = temp->next;
	}
	return (stackA);
}

int	ft_chknum(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i] == '0')
		i++;
	while (str[i])
	{
		j++;
		if (!ft_isdigit(str[i]) || j > 10)
			return (0);
		i++;
	}
	return (1);
}

int	ft_lstval(t_list *stack, int val)
{
	while (stack)
	{
		if (stack->content == val)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int is_ordered(t_list *stack)
{
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_list	*ft_delone(t_list *stack)
{
	t_list	*temp;

	if (!stack)
		return (NULL);
	if (stack->next)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
	return (stack);
}
