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
#include "libft/libft.h"

int	*ft_init_stack(t_stack *stack, int argc, char **argv)
{
	int 	i;
	int		val;
	int		*arr;
	t_list	*temp;

	i = 0;
	arr = malloc(sizeof(int) * (argc - 1)); // argc is one more than argv, to be kept for sorting purposes
	if (!arr)
		return (NULL);
	while (*argv[++i])
	{
		val = ft_atoi(argv[i]);
		temp = ft_lstnew(val);
		if (!temp)
			return (NULL); // Add free of the whole list and of arr
		ft_lstadd_back(stack, temp); // Fix list to check for nulls
		if (!ft_arr_check(val))
			raise_error;
			return (NULL); // implement free
		arr[i] = val;
	}
	return (arr);
}

void	ft_push_swap(t_stack *stackA, t_stack *stackB, int *arr)
{
	// do I need a temp or it is okay since the only modifiable content is
	// waht is internal to the array?
	while (stackA)
	{
		stackA->pos = get_arr_pos(arr, , stackA->content);
		stackA = stackA->next;
	}
}

int main(int argc, char **argv)
{
	t_stack	*stackA;
	t_stack *stackB; // Should it use stack or common lists?
	int		*arr;

	if (argc < 2)
		return (1);
	arr = ft_init_stack(stackA, argc, argv);
	if (is_ordered(stackA))
		ft_printf("WIN");
	if (argc < 5)
		fast_solve(stackA);
		return(0);
	ft_sort_int(&arr, argc - 1);
	ft_push_swap(stackA, stackB);
	return (0);
}
