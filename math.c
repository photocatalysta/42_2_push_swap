/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:30:15 by jsala             #+#    #+#             */
/*   Updated: 2024/02/15 17:40:25 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_abs_sum(int a, int b)
{
	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;
	return (a + b);
}

int ft_abs_min(int val, int val_rev)
{
	if (val < -val_rev)
		return (val);
	else
		return (val_rev);
}

int ft_max(int i, int j)
{
	if (i > j)
		return (i);
	return (j);
}

int	ft_min(int i, int j)
{
	if (i < j)
		return (i);
	return (j);
}
