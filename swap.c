/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 09:59:48 by jsala             #+#    #+#             */
/*   Updated: 2024/02/14 10:06:48 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void swap(t_list *lst)
{
    t_list  *temp;

    temp = lst;
    temp->next = lst->next->next; //??
    lst->next->next = temp;
    // lst is the first element
    // lst->next is the second element

    // (lst->next)->next = lst
    // (lst)->next = lst->next->next
}
