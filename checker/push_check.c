/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:01:55 by jsala             #+#    #+#             */
/*   Updated: 2024/02/17 10:43:04 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	ft_push_check(t_list **stackFrom, t_list **stackTo)
{
	t_list *temp;

	if (!stackFrom || !(*stackFrom))
		free_exit(stackFrom, stackTo, 1);
	temp = ft_lstnew((*stackFrom)->content, (*stackFrom)->position);
	ft_lstadd_front(stackTo, temp);
	temp = *stackFrom;
	*stackFrom = (*stackFrom)->next;
	free(temp);
}

