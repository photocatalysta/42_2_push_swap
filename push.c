/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:01:55 by jsala             #+#    #+#             */
/*   Updated: 2024/02/16 15:30:26 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void ft_push(t_list **stackFrom, t_list **stackTo, char c)
{
	t_list *temp;

	if (!stackFrom || !(*stackFrom))
		free_exit(stackFrom, stackTo, 1);
	temp = ft_lstnew((*stackFrom)->content, (*stackFrom)->position);
	ft_lstadd_front(stackTo, temp);
	temp = *stackFrom;
	*stackFrom = (*stackFrom)->next;
	free(temp);
	write (1, "p", 1);
	write (1, &c, 1);
	write (1, "\n", 1);
}

/*
	while (tmp->next->next)
		tmp->next = tmp->next->next;
	tmp->next->next = stacks->stack_a;
	stacks->stack_a = tmp->next;
	tmp->next = NULL;
*/
