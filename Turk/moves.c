/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 09:11:42 by jsala             #+#    #+#             */
/*   Updated: 2024/02/17 10:50:23 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_move(t_list **stack_a, t_list **stack_b, int *mov_a, int *mov_b)
{
	while (*mov_a != 0 && *mov_b !=0)
	{
		if ((*mov_a) * (*mov_b) > 0)
		{
			if (*mov_a < 0)
			{
				ft_rotate_rev_both(stack_a, stack_b); // Move the move change to the functions themselves to save lines and space
				(*mov_a)++;
				(*mov_b)++;
			}
			else
			{
				ft_rotate_both(stack_a, stack_b);
				(*mov_a)--;
				(*mov_b)--;
			}
		}
		if (*mov_a != 0)
			ft_move_stack(stack_a, mov_a, 'a');
		if (*mov_b != 0)
			ft_move_stack(stack_b, mov_b, 'b');
	}
	write(1, "pb\n", 3);
	ft_push(stack_a, stack_b);
}

void	ft_move_stack(t_list **stack, int *mov, char c)
{
	if (*mov < 0)
	{
		write(1, "rr", 2);
		write(1, &c, 1);
		write(1, "\n", 1);
		ft_rotate_rev(stack);
		(*mov)++;
	}
	else if (*mov > 0)
	{
		write(1, "r", 2);
		write(1, &c, 1);
		write(1, "\n", 1);
		ft_rotate(stack);
		(*mov)--;
	}
}

/*
Goes through all the different numbers starting from the top of the stack_a
- Checks the amount of moves needed to properly be stacked in B
- After the first one is set, checks for a max of moves - 1 positions
- If any position gets a lower number of moves, substitutes the instructions
Once it is obtained the correct value to be pushed, run the commands
*/
void	ft_get_moves_A(t_list *stack_a, t_list *stack_b, int *mov_a, int *mov_b)
{
	/*Get the position that can be moved from A to B in the smallest amount of moves*/
	int	abs_cost;
	int	abs_lowest_cost;
	int	temp_mov_a;
	int temp_mov_b;

	temp_mov_a = 0; // Tracks the current position
	temp_mov_b = 0;
	abs_cost = ft_calc_abs_cost(stack_a, stack_b, &mov_a, &mov_b); // Checks for the current cost
	abs_lowest_cost = abs_cost; // Saves the cheapest move
	// Being at a position that is further than abs_lowest_cost doesn't make sense, save calculations
	while (stack_a)
	{
		abs_cost = ft_calc_abs_cost(stack_a, stack_b, &temp_mov_a, &temp_mov_b); // Pass temp_mov as a way for it to update here too
		if (abs_cost == 0)
			return ;
		if (abs_cost < abs_lowest_cost)
		{
			abs_lowest_cost = abs_cost;
			*mov_a = temp_mov_a;
			*mov_b = temp_mov_b;
		}
		stack_a = stack_a->next;
	}
}

void	ft_stack_sort(t_list **stack_a, t_list **stack_b)
{
	int	mov_a;
	int	mov_b;

	// First part, push to B in a ordered way
	mov_a = 0;
	mov_b = 0;
	while (!is_ordered(*stack_a) || ft_lstsize(*stack_a) > 3)
	{
		ft_get_moves_A(*stack_a, *stack_b, &mov_a, &mov_b);
		print_list(*stack_a, 10);
		printf("What is the value for A and B?\nA: %i, B: %i;\n", mov_a, mov_b);
		ft_move(stack_a, stack_b, &mov_a, &mov_b);
		print_list(*stack_a, 10);
		printf("What is the value for A and B?\nA: %i, B: %i;\n", mov_a, mov_b);
	}
	print_list(*stack_a, 10);
	if (!is_ordered(*stack_a))
		ft_fast_sort(stack_a);
	print_list(*stack_a, 10);
	//while (ft_lstsize(*stack_b) > 0 && !is_ordered(stack_a))
	//	push_b_to_a();
}
