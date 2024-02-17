/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 22:13:01 by jsala             #+#    #+#             */
/*   Updated: 2024/02/17 10:46:37 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int main(int argc, char **argv)
{
	t_list	*stackA;
	t_list	*stackB;
	int		*arr;

	if (argc < 2)
		return (0);
	arr = ft_calloc(argc - 1, sizeof(int));
	if (!arr)
		return (1);
	stackA = NULL;
	stackA = ft_init_list(argc, argv, stackA, &arr);
	arr = ft_sort_int(arr, argc - 1);
	stackA = ft_init_pos(stackA, arr, argc);
	free(arr);
	// init stackB here for convenience;
	stackB = NULL;
//	test_stack(&stackA, &stackB);
	ft_push_swap(&stackA, &stackB);
	free_exit(&stackA, &stackB, 0);
	return (0);
}
