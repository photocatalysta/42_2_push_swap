/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 09:11:42 by jsala             #+#    #+#             */
/*   Updated: 2024/02/16 09:50:26 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_move(t_list **stackA, t_list **stackB, int *mov_a, int *mov_b)
{
	while (*mov_a != 0 && *mov_b !=0)
	{
		if ((*mov_a) * (*mov_b) > 0)
		{
			if (*mov_a < 0)
			{
				ft_rotate_rev_both(stackA, stackB); // Move the move change to the functions themselves to save lines and space
				(*mov_a)++;
				(*mov_b)++;
			}
			else
			{
				ft_rotate_both(stackA, stackB);
				(*mov_a)--;
				(*mov_b)--;
			}
		}
		if (*mov_a != 0)
			ft_move_stack(stackA, mov_a, 'a');
		if (*mov_b != 0)
			ft_move_stack(stackB, mov_b, 'b');
	}
	write(1, "pb\n", 3);
	ft_push(stackA, stackB);
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
Goes through all the different numbers starting from the top of the stackA
- Checks the amount of moves needed to properly be stacked in B
- After the first one is set, checks for a max of moves - 1 positions
- If any position gets a lower number of moves, substitutes the instructions
Once it is obtained the correct value to be pushed, run the commands
*/
void	ft_get_moves_A(t_list *stackA, t_list *stackB, int *mov_a, int *mov_b)
{
	/*Get the position that can be moved from A to B in the smallest amount of moves*/
	int	abs_cost;
	int	abs_lowest_cost;
	int	temp_mov_a;
	int temp_mov_b;

	temp_mov_a = 0; // Tracks the current position
	temp_mov_b = 0;
	abs_cost = ft_calc_abs_cost(stackA, stackB, &mov_a, &mov_b); // Checks for the current cost
	abs_lowest_cost = abs_cost; // Saves the cheapest move
	// Being at a position that is further than abs_lowest_cost doesn't make sense, save calculations
	while (stackA)
	{
		abs_cost = ft_calc_abs_cost(stackA, stackB, &temp_mov_a, &temp_mov_b); // Pass temp_mov as a way for it to update here too
		if (abs_cost == 0)
			return ;
		if (abs_cost < abs_lowest_cost)
		{
			abs_lowest_cost = abs_cost;
			*mov_a = temp_mov_a;
			*mov_b = temp_mov_b;
		}
		stackA = stackA->next;
	}
}

void	ft_stack_sort(t_list **stackA, t_list **stackB)
{
	int	mov_a;
	int	mov_b;

	// First part, push to B in a ordered way
	mov_a = 0;
	mov_b = 0;
	while (!is_ordered(*stackA) || ft_lstsize(*stackA) > 3)
	{
		ft_get_moves_A(*stackA, *stackB, &mov_a, &mov_b);
		print_list(*stackA, 10);
		printf("What is the value for A and B?\nA: %i, B: %i;\n", mov_a, mov_b);
		ft_move(stackA, stackB, &mov_a, &mov_b);
		print_list(*stackA, 10);
		printf("What is the value for A and B?\nA: %i, B: %i;\n", mov_a, mov_b);
	}
	print_list(*stackA, 10);
	if (!is_ordered(*stackA))
		ft_fast_sort(stackA);
	print_list(*stackA, 10);
	//while (ft_lstsize(*stackB) > 0 && !is_ordered(stackA))
	//	push_b_to_a();
}
