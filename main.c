/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 22:13:01 by jsala             #+#    #+#             */
/*   Updated: 2024/02/14 13:17:09 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
/*
int	ft_push_swap(t_list *stackA, t_list *stackB)
{
	int	l_stack;
	// do I need a temp or it is okay since the only modifiable content is
	// waht is internal to the array?

	l_stack = ft_list_size(stackA);
	if (l_stack == 1 || is_ordered(stackA))
		return(success_exit());
	// Start the right algorithm based on the different cases
	else

	if (l_stack < 6)
		fast_sort(stackA, stackB);
	else
		fast_sort(stackA, stackB);

	while (stackA)
	{
		stackA->pos = get_arr_pos(arr, , stackA->content);
		stackA = stackA->next;
	}
}
*/
int main(int argc, char **argv)
{
	t_list	*stackA;
	t_list	*stackB;

	stackA = malloc(sizeof(t_list));
	if (!stackA)
		free_exit(stackA, NULL, 1);
	stackA = ft_init_list(argc, argv, stackA);
	// init stackB here for convenience;
	stackB = ft_calloc(sizeof(t_list), argc - 1);
	if (!stackB)
		free_exit(stackA, stackB, 1);
//	ft_push_swap(stackA, stackB);
	return (0);
}
