/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:01:55 by jsala             #+#    #+#             */
/*   Updated: 2024/02/16 09:43:11 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void ft_push(t_list **stackFrom, t_list **stackTo)
{
	t_list *temp;

	if (!stackFrom || !(*stackFrom))
		free_exit(*stackFrom, *stackTo, 1);
	temp = ft_lstnew((*stackFrom)->content);
	ft_lstadd_front(stackTo, temp);

	temp = *stackFrom;
	*stackFrom = (*stackFrom)->next;
	free(temp);
}

/*
	while (tmp->next->next)
		tmp->next = tmp->next->next;
	tmp->next->next = stacks->stack_a;
	stacks->stack_a = tmp->next;
	tmp->next = NULL;
*/
