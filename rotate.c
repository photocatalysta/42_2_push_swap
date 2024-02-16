/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:07:44 by jsala             #+#    #+#             */
/*   Updated: 2024/02/16 15:12:44 by jsala            ###   ########.fr       */
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

void ft_rotate(t_list **stack)
{
	t_list  *temp;

	if (!stack || !(*stack) || (*stack)->next == NULL)
		return ;
	temp = ft_lstnew((*stack)->content, (*stack)->position);
	temp->next = NULL;
	ft_lstadd_back(stack, temp);
	temp = (*stack)->next;
	*stack = temp;
	free(temp);
}

void ft_rotate_rev(t_list **stack)
{
	t_list	*temp;
	t_list	*new;

	if (!stack || !(*stack) || (*stack)->next == NULL)
		return ;
	temp = *stack;
	while (temp->next->next)
		temp = temp->next;
	new = ft_lstnew(temp->next->content, temp->next->position);
	ft_lstadd_front(stack, new);
	free(temp->next);
	temp->next = NULL;
}
