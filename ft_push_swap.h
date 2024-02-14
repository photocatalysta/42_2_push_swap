/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala <jsala@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 22:16:31 by jsala             #+#    #+#             */
/*   Updated: 2024/02/14 12:36:49 by jsala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"

//ADD FUNCTIONS

void	ft_sort_int(int	**arr, int size);
int		get_arr_pos(int *arr, int size, int val);
t_list	*ft_init_list(int argc, char **argv, t_list *stack);
t_list	*ft_init_args(t_list *stack, char **argv);
t_list	*ft_delone(t_list *stack);
int		ft_chknum(char *str);

void	rotate(t_list *lst);
void	rotate_rev(t_list *stack);
void	rotate_both(t_list *a, t_list *b);
void	rotate_rev_both(t_list *a, t_list *b);
void	push_a(t_list *a, t_list *b);
void	push_b(t_list *a, t_list *b);

void	ft_sort_int(int	**arr, int size);
int		get_arr_pos(int *arr, int size, int val);

int		ft_lstval(t_list *stack, int val);
int 	is_ordered(t_list *stack);

void	free_exit(t_list *stackA, t_list *stackB, int exit_val);

// Testing functions
void	print_list(t_list *list);

#endif
