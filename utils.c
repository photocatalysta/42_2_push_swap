/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 22:23:42 by jsala             #+#    #+#             */
/*   Updated: 2024/02/14 19:32:38 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_chknum(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
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

void	free_exit(t_list *stackA, t_list *stackB, int exit_val)
{
	if (exit_val == 1)
		write(2, "Error\n", 6);
	if (stackA)
		ft_clear(&stackA);
	if (stackB)
		ft_clear(&stackB);
	exit(exit_val);
}
