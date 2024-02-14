/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:38:29 by jsala             #+#    #+#             */
/*   Updated: 2024/02/14 13:17:26 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdio.h>

t_list	*ft_init_list(int argc, char **argv, t_list *stack)
{
	int	i;

	i = 0;
	if (argc < 2)
			stack = NULL;//read_stdin;
	else
	{
		while (++i < argc)
		{
			if (!ft_chknum(argv[i]))
				free_exit(stack, NULL, 1);
		}
	/*	if (argc == 2)
			stack = ft_init_str(stack, argv[1]);
		else
			*/stack = ft_init_args(stack, argv);
		// No res or free check needed, we can exit... // Need to check if arguments passed are wrong too
	}
	return (stack);
}

t_list	*ft_init_args(t_list *stack, char **argv)
{
	int			i;
	long int	temp_val;
	int			val;
	t_list		*temp;

	i = 0;
	while (argv[++i]) // What happens if I pass a 0 value as one of the arguments?
	{
		temp_val = ft_atol(argv[i]);
		if (temp_val < INT_MIN || temp_val > INT_MAX)
			free_exit(stack, NULL, 1);
		val = (int) temp_val;
		if (i == 1)
		{
			stack->content = val;
			continue;
		}
		temp = ft_lstnew(val);
		if (!temp)
			free_exit(stack, NULL, 1);
		if (ft_lstval(stack, val))
			free_exit(stack, NULL, 1);
		ft_lstadd_back(&stack, temp); // Fix list to check for nulls
	}
	return (stack);
}
