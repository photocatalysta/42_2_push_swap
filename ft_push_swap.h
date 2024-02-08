/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jacopo.sala@student.barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 22:16:31 by jsala             #+#    #+#             */
/*   Updated: 2024/01/16 22:41:57 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
	
} t_stack;

//ADD FUNCTIONS



void    rotate_both(t_stack *a, t_stack *b);
void    rotate_rev_both(t_stack *a, t_stack *b);
void    ft_print_error(void);
int     is_ordered(t_list *a);
void	ft_sort_int(int	**arr, int size);
int     get_arr_pos(int *arr, int size, int val);
void    ft_print_error(void);

#endif