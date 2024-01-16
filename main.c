/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jacopo.sala@student.barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 22:13:01 by jsala             #+#    #+#             */
/*   Updated: 2024/01/16 22:47:03 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_init_stack(t_stack *stack, char **argv)
{
	int i;
	int temp;

	i = 0;
	while (*argv[++i])
	{
		temp = ft_atoi(argv[i]);
		ft_new_stack(temp);
		if ...
			return (NULL); // NEED TO VERIFY THAT THERE IS NO DOUBLE ENTRY
	}
}

void	ft_push_swap(void)
{
	
}

int main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc < 2)
		return (1);
	ft_init_stack(stack, argv);
	ft_push_swap();
	return (0);
}
