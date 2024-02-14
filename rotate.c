/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:07:44 by jsala             #+#    #+#             */
/*   Updated: 2024/02/14 11:33:07 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void rotate_both(t_list *a, t_list *b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 4);
}

void rotate_rev_both(t_list *a, t_list *b)
{
	rotate_rev(a);
	rotate_rev(b);
	write(1, "rrr\n", 4);
}

//Should I do this on a copy or on the actual array?

void rotate(t_list *stack)
{ //UP
	t_list  *temp;

	temp = stack;
	ft_lstadd_back(&stack, temp);
	ft_delone(stack);
}

void rotate_rev(t_list *stack)
{ // DOWN -> Check correct function
	t_list  *temp;

	temp = ft_lstlast(stack);
	ft_lstadd_front(&stack, temp);
	ft_delone(ft_lstlast(stack));
}
