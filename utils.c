/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jacopo.sala@student.barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 22:23:42 by jsala             #+#    #+#             */
/*   Updated: 2024/01/16 22:40:52 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void    ft_print_error(void)
{
	write(2, "Error\n", 6);
}

int is_ordered(t_list *a)
{
	while (a->next)
	{
		if (a->content > a->next->content)
			return (0);
	}
	return (1);
}

void	ft_sort_int(int	**arr, int size)
{
	int	i;
	int	**temp;

	i = 0;
	temp = NULL;
	while (++i < size)
		if (*arr[i-1] < *arr[i])
		{
			*temp = *arr[i-1];
			*arr[i-1] = *arr[i];
			*arr[i] = *temp;
		}
}

int	get_arr_pos(int *arr, int size, int val) //What if there are 2 identical numbers?
{
	int	i;

	i = 0;
	while (i < size)
	{	
		if (arr[i] == val)
			return (0);
		i++;
	}
	return (val);
}
