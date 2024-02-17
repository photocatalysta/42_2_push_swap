/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:07:44 by jsala             #+#    #+#             */
/*   Updated: 2024/02/17 10:30:51 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	ft_rotate_both_check(t_list **stackA, t_list **stackB)
{
	ft_rotate(stackA);
	ft_rotate(stackB);
}

void	ft_rotate_rev_both_check(t_list **stackA, t_list **stackB)
{
	ft_rotate_rev(stackA);
	ft_rotate_rev(stackB);
}

void	ft_rotate_check(t_list **stack)
{
	t_list	*temp;

	if (!stack || !(*stack) || (*stack)->next == NULL)
		return ;
	temp = ft_lstnew((*stack)->content, (*stack)->position);
	ft_lstadd_back(stack, temp);
	temp = (*stack)->next;
	free(*stack);
	*stack = temp;
}

void	ft_rotate_rev_check(t_list **stack)
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
