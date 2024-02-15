/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:41:29 by jsala             #+#    #+#             */
/*   Updated: 2024/02/15 17:39:24 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int ft_get_best_cost(int l_stackA, int l_stackB, int *costA, int *costB)
{
	/*
		Calculate the actual best set of moves:
		- If costA and costB are both positive -> return MAX
		- If costA and costB are both negative -> return MAX in abs terms
		- Else, check if costa - len A < sum (abs(costA) + abs(costB))

		Double check for cases were costs are 0;
	*/
	if (*costA > 0 && *costB > 0)
		return (ft_max(*costA, *costB));
	else if (*costA < 0 && *costB < 0)
		return (ft_min(*costA, *costB));
	else
		return (ft_abs_sum(*costA, *costB));
	/* Calc rev stackA
	if (*costA < 0)
	{
		if (l_stackA + *costA < *costB - *costA)
		{
			*costA = l_stackA + *costA; // Change sign and get the opposite value
			return (*costA);
		}
		else if (l_stackB - *costB < *costB - *costA)
		{
			*costB = *costB - l_stackB; // Change sign and get the opposite value
			return (*costB);
		}
	}
	else if (*costB < 0)
	{
		if (l_stackB + *costB < *costA - *costB)
			*costB = l_stackB + *costB; // Change sign and get the opposite value
		else if (l_stackA - *costA < *costA - *costB)
			*costA = *costA - l_stackA; // Change sign and get the opposite value
	}*/
}

// Calculate moves to reach top or end of stackA from pos X

// Calculate moves to move stack B to have the top available for the push

// Calculate Save position and quantity of moves if best situation:
// Pos A, Moves B, Absolute value of moves...
// Could be the sum of both or could just be possible to benefit from joint rotations

int	ft_cost_B(t_list *stackB, int val)
{
	int	len_b;
	int	pos;

	if (!stackB)
		return (0);
	pos = 1;
	while (stackB->next)
	{
		if (stackB->content > val && val < stackB->next->content) // This works going forward and if ordered B
			break ;
		stackB = stackB->next;
		pos++;
	}
	len_b = ft_lstsize(stackB);
	if (len_b - pos > pos)
		return (pos);
	else
		return (pos - len_b); // Do some debugging about the actual values to not get fooled by the 0s and 1s
}

int	ft_calc_cost(t_list *stackA, t_list *stackB, int *costA, int *costB)
{
	int	costA;
	int	val;
	int	costB;
	int cost;

//	Double check the actual value of new_pos... does it start from 0 or 1? Cost A
	costA = ft_abs_min(costA, costA - ft_lstsize(stackA));
	if (!stackB)
		return (costA);
	while (--costA >= 0)
		stackA = stackA->next;
	val = stackA->content;
	costB = ft_cost_B(stackB, val);
	cost = ft_get_best_cost(ft_lstsize(stackA), ft_lstsize(stackB), &costA, &costB);
	return (cost);
}
