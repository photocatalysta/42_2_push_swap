/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:07:44 by jsala             #+#    #+#             */
/*   Updated: 2024/01/31 11:07:44 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void rotate_both(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 4);
}

void rotate_rev_both(t_stack *a, t_stack *b)
{
	rotate_rev(a);
	rotate_rev(b);
	write(1, "rrr\n", 4);
}
