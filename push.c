/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:01:55 by jsala             #+#    #+#             */
/*   Updated: 2024/02/14 11:33:33 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void push_a(t_list *a, t_list *b)
{
    t_list *temp;

    temp = ft_lstnew(a->content);
    ft_delone(a);
    ft_lstadd_front(&b, temp);
}

void push_b(t_list *a, t_list *b)
{
    t_list *temp;

    temp = ft_lstnew(b->content);
    ft_delone(b);
    ft_lstadd_front(&a, temp);
}

/*
    while (tmp->next->next)
        tmp->next = tmp->next->next;
	tmp->next->next = stacks->stack_a;
	stacks->stack_a = tmp->next;
	tmp->next = NULL;
*/
