/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:07:44 by jsala             #+#    #+#             */
/*   Updated: 2024/02/14 14:50:27 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void ft_rotate_both(t_list **stackA, t_list **stackB)
{
	ft_rotate(stackA);
	ft_rotate(stackB);
	write(1, "rr\n", 4);
}

void ft_rotate_rev_both(t_list **stackA, t_list **stackB)
{
	ft_rotate_rev(stackA);
	ft_rotate_rev(stackB);
	write(1, "rrr\n", 4);
}

//Should I do this on a copy or on the actual array?

void ft_rotate(t_list **stack)
{
	t_list  *temp;

	temp = ft_lstnew((*stack)->content);
	temp->next = NULL;
	ft_lstadd_back(stack, temp);
	temp = *stack;
	(*stack) = (*stack)->next;
	free(temp);
}

void ft_rotate_rev(t_list **stack)
{
	t_list  *temp;
	t_list  *temp2;

	temp = *stack;
	while (temp->next->next)
		temp = temp->next;
	temp2 = temp->next;
	temp->next = NULL;
	ft_lstadd_front(stack, temp2);
}
