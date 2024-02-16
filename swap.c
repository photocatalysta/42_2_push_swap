/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 09:59:48 by jsala             #+#    #+#             */
/*   Updated: 2024/02/16 15:42:32 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void ft_swap(t_list **lst)
{
	t_list  *temp;

	if (!lst || !(*lst) || !(*lst)->next)
		free_exit(lst, NULL, 1);
	temp = (*lst)->next;
	(*lst)->next = temp->next;
	temp->next = *lst;
	(*lst) = temp;
}
/*
void ft_swap_test(t_list *lst)
{
	t_list  *temp;

	if (!lst || !(*lst) || !(*lst)->next)
		free_exit(lst, NULL, 1);
	temp = (*lst)->next;
	(*lst)->next = (*lst)->next->next;
	temp->next = *lst;
	(*lst) = temp;
}
*/
