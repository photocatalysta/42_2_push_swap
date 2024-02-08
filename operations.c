/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:01:55 by jsala             #+#    #+#             */
/*   Updated: 2024/01/30 18:01:55 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void push_a(t_list *a, t_list *b)
{
    t_list *temp;

    temp = ft_lstnew(a->content);
    ft_lstdelone(a, free);
    ft_lstadd_front(b, temp);
}

void push_b(t_list *a, t_list *b)
{
    t_list *temp;

    temp = ft_lstnew(b->content);
    ft_lstdelone(b, free);
    ft_lstadd_front(a, temp);
}

void swap(t_list *lst)
{
    t_list  *temp;

    temp = lst;
    temp->next = lst->next->next; ??
    lst->next->next = temp;
    // lst is the first element
    // lst->next is the second element

    // (lst->next)->next = lst
    // (lst)->next = lst->next->next
}

//Should I do this on a copy or on the actual array?

void rotate(t_list *lst)
{ //UP
    t_list  *temp;

    temp = lst;
    ft_lstadd_back(lst, temp);
    ft_lstdelone(lst, free);
}

void rotate_rev(t_list *lst)
{ // DOWN -> Check correct function
    t_list  *temp;

    temp = ft_lstlast(lst);
    ft_lstadd_front(lst, temp);
    ft_lstdelone_end(lst, free);
}

/*
    while (tmp->next->next)
        tmp->next = tmp->next->next;
	tmp->next->next = stacks->stack_a;
	stacks->stack_a = tmp->next;
	tmp->next = NULL;
*/
