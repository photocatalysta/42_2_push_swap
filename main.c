/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 22:13:01 by jsala             #+#    #+#             */
/*   Updated: 2024/03/11 09:07:31 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		*arr;

	if (argc < 2)
		return (1);
	arr = ft_calloc(argc - 1, sizeof(int));
	if (!arr)
		return (2);
	stack_a = NULL;
	stack_a = ft_init_list(argc, argv, stack_a, &arr);
	arr = ft_sort_int(arr, argc - 1);
	stack_a = ft_init_pos(stack_a, arr, argc);
	free(arr);
	stack_b = NULL;
	ft_push_swap(&stack_a, &stack_b);
	free_exit(&stack_a, &stack_b, 0);
}
