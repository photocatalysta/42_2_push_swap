/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:41:29 by jsala             #+#    #+#             */
/*   Updated: 2024/02/17 10:50:23 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int ft_get_best_cost(int l_stack_a, int l_stack_b, int *costA, int *costB)
{
	(void) l_stack_a;
	(void) l_stack_b;
	//int	abs_cost_a;
	//int	abs_cost_b;
	//int	cost; // Should be calculated in the case no shared move is done
	/*
		Calculate the actual best set of moves:
		- If costA and costB are both positive -> return MAX
		- If costA and costB are both negative -> return MAX in abs terms
		- Else, check if costa - len A < sum (abs(costA) + abs(costB))

		Double check for cases were costs are 0;
	*/
	if (*costA > 0 && *costB > 0)
		return (ft_max(*costA, *costB)); // Double check if it is done via absolute values or not...
	else if (*costA < 0 && *costB < 0)
		return (ft_min(*costA, *costB)); // Double check if it is done via absolute values or not...
	else
		return (ft_abs_sum(*costA, *costB));
	/* Calc rev stack_a
	abs_cost_a = ft_abs(*costA);
	abs_cost_b = ft_abs(*costB);
	cost = ft_abs_sum(*costA, *costB);
	if (l_stack_a - abs_cost_a < cost)
		*costA = (l_stack_a - abs_cost_a) * (cost_a / abs_cost_a);
	else if (l_stack_b - abs_cost_b < cost)
		*costB = (l_stack_b - abs_cost_b) * (cost_b / abs_cost_b);
	cost = ft_abs(*costA + *costB); // Double check if it is done via absolute values or not...
	reutrn (cost);
	}*/
}

// Calculate moves to reach top or end of stack_a from pos X

// Calculate moves to move stack B to have the top available for the push

// Calculate Save position and quantity of moves if best situation:
// Pos A, Moves B, Absolute value of moves...
// Could be the sum of both or could just be possible to benefit from joint rotations

int	ft_cost_B(t_list *stack_b, int val)
{
	int	len_b;
	int	pos;

	if (!stack_b)
		return (0);
	pos = 1;
	while (stack_b->next)
	{
		if (stack_b->content > val && val < stack_b->next->content) // This works going forward and if ordered B
			break ;
		stack_b = stack_b->next;
		pos++;
	}
	len_b = ft_lstsize(stack_b);
	if (len_b - pos > pos)
		return (pos);
	else
		return (pos - len_b); // Do some debugging about the actual values to not get fooled by the 0s and 1s
}

int	ft_calc_abs_cost(t_list *stack_a, t_list *stack_b, int *costA, int *costB)
{
	int	val;
	int cost;

//	Double check the actual value of new_pos... does it start from 0 or 1? Cost A
	*costA = ft_abs_min(*costA, *costA - ft_lstsize(stack_a));
	if (!stack_b)
		return (*costA);
	while (--costA >= 0) // Creful about this
		stack_a = stack_a->next;
	val = stack_a->content;
	*costB = ft_cost_B(stack_b, val);
	cost = ft_get_best_cost(ft_lstsize(stack_a), ft_lstsize(stack_b), costA, costB);
	return (cost);
}
